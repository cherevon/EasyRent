DROP PROCEDURE dbo.er_users_update
GO

CREATE PROCEDURE dbo.er_users_update
/*Добавление/изменение пользователя в системе EasyRent*/
(
	@user_id INT OUTPUT, /*Идентификатор пользователя (если NULL, то будем создан новый пользователь)*/
	@surname VARCHAR(100), /*Фамилия*/
	@name VARCHAR(100), /*Имя*/
	@patronymic VARCHAR(100), /*Отчество*/
	@username VARCHAR(50), /*Логин*/
	@password VARCHAR(255), /*Пароль*/
	@city_id INT /*Город, в котором проживает пользователь*/
)
AS
	DECLARE @err_msg VARCHAR(150);

	-- проверяем существование указанного идентификатора пользователя
	IF @user_id IS NOT NULL AND NOT EXISTS (SELECT * FROM er_users WHERE id = @user_id)
	BEGIN		
		SET @err_msg = 'Пользователь с идентификатором ' + CAST(@user_id AS VARCHAR(10)) + ' не найден!';
		THROW 60000, @err_msg, 0;
	END

	-- проверяем уникальность логина пользователя
	IF (@user_id IS NOT NULL AND EXISTS (SELECT * FROM er_users WHERE username = @username AND id <> @user_id)) OR (@user_id IS NULL AND EXISTS (SELECT * FROM er_users WHERE username = @username))
	BEGIN
		SET @err_msg = 'Пользователь с логином "' + @username + '" уже существует в EasyRent!';
		THROW 60000, @err_msg, 0;
	END

	-- проверяем существование города
	IF @city_id IS NULL
	BEGIN
		SET @err_msg = 'Не задан город, в котором проживает пользователь!';
		THROW 60000, @err_msg, 0;
	END
	ELSE IF NOT EXISTS (SELECT * FROM cities WHERE id = @city_id)
	BEGIN
		SET @err_msg = 'Город с идентификатором ' + CAST(@city_id AS VARCHAR(10)) + ' не найден!';
		THROW 60000, @err_msg, 0;
	END

	-- добавляем нового пользователя или обновляем информацию о существующем
	IF @user_id IS NULL
	BEGIN
		INSERT INTO er_users(surname, name, patronymic, username, pswd, city_id) VALUES(@surname, @name, @patronymic, @username, @password, @city_id);
		SELECT @user_id = SCOPE_IDENTITY() FROM er_users;
	END
	ELSE
		UPDATE er_users SET surname = @surname, name = @name, patronymic = @patronymic, username = @username, pswd = @password, city_id = @city_id WHERE id = @user_id
GO

exec er_users_update 1, 'Черевичко', 'Сергей', 'Андреевич', 'cherevon', 'fighterfought1', 10;
select * from er_users