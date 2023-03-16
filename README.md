Программа выполнена одним человеком.

Управление осуществляется следующим образом, программа выводит на экран номера возможных действий, для выбора необходимого действия нужно вводить с клавиатуры номер выбранного варианта.
При старте программы осуществляется выбор регистрации либо авторизации, производится проверка наличия, уникальности имени и правил ввода логина/пароля. Далее осуществляется выбор просмотра сообщений пользователя где выводятся все общие сообщения чата и личные сообщения от других пользователей, просмотр пользователей чата, где можно посмотреть всех пользователей чата и увидеть по маркеру под каким пользователем сейчас находимся в чате. Отправить сообщения всем либо конкретному пользователю с проверкой существования имени пользователя.

Проект содержит классы User - клиент чата + обработка исключений, Message - сообщение чата, Chat - функционал чата 

Класс User:
_name - имя пользователя (строка)
_login - логин пользователя (строка)
_password - пароль пользователя (строка)

Класс Message:
_sender - отправитель
_recipient  - получатель 
_text - текст сообщения

Класс Chat:

UserLogin - авторизация

UserRegistration - регистрация пользователя

ShowChat - сообщения пользователя

ShowAllUsers - пользователи чата

AddMessage - создаём сообщение

StartChat - вход в чат

ShowLoginMenu - меню авторизации

ShowUserMenu - меню авторизированного пользователя
