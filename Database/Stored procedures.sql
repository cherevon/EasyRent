DROP PROCEDURE dbo.er_users_update
GO

CREATE PROCEDURE dbo.er_users_update
/*����������/��������� ������������ � ������� EasyRent*/
(
	@user_id INT OUTPUT, /*������������� ������������ (���� NULL, �� ����� ������ ����� ������������)*/
	@surname VARCHAR(100), /*�������*/
	@name VARCHAR(100), /*���*/
	@patronymic VARCHAR(100), /*��������*/
	@username VARCHAR(50), /*�����*/
	@password VARCHAR(255), /*������*/
	@city_id INT /*�����, � ������� ��������� ������������*/
)
AS
	DECLARE @err_msg VARCHAR(150);

	-- ��������� ������������� ���������� �������������� ������������
	IF @user_id IS NOT NULL AND NOT EXISTS (SELECT * FROM er_users WHERE id = @user_id)
	BEGIN		
		SET @err_msg = '������������ � ��������������� ' + CAST(@user_id AS VARCHAR(10)) + ' �� ������!';
		THROW 60000, @err_msg, 0;
	END

	-- ��������� ������������ ������ ������������
	IF (@user_id IS NOT NULL AND EXISTS (SELECT * FROM er_users WHERE username = @username AND id <> @user_id)) OR (@user_id IS NULL AND EXISTS (SELECT * FROM er_users WHERE username = @username))
	BEGIN
		SET @err_msg = '������������ � ������� "' + @username + '" ��� ���������� � EasyRent!';
		THROW 60000, @err_msg, 0;
	END

	-- ��������� ������������� ������
	IF @city_id IS NULL
	BEGIN
		SET @err_msg = '�� ����� �����, � ������� ��������� ������������!';
		THROW 60000, @err_msg, 0;
	END
	ELSE IF NOT EXISTS (SELECT * FROM cities WHERE id = @city_id)
	BEGIN
		SET @err_msg = '����� � ��������������� ' + CAST(@city_id AS VARCHAR(10)) + ' �� ������!';
		THROW 60000, @err_msg, 0;
	END

	-- ��������� ������ ������������ ��� ��������� ���������� � ������������
	IF @user_id IS NULL
	BEGIN
		INSERT INTO er_users(surname, name, patronymic, username, pswd, city_id) VALUES(@surname, @name, @patronymic, @username, @password, @city_id);
		SELECT @user_id = SCOPE_IDENTITY() FROM er_users;
	END
	ELSE
		UPDATE er_users SET surname = @surname, name = @name, patronymic = @patronymic, username = @username, pswd = @password, city_id = @city_id WHERE id = @user_id
GO

exec er_users_update 1, '���������', '������', '���������', 'cherevon', 'fighterfought1', 10;
select * from er_users