SnowEngine
by SnegirSoft

Для использования требуется 64-разрядная (может быть, возможно как-то ухитриться использовать 32-разрядную) ОС Windows 7 и выше (есть вероятность, что подойдёт XP и Vista), MS Visual Studio не ниже 2010 (минимальная версия 10.0.40219.1), а также установленная библиотека SFML (рекомендуется версия не ниже 2.5.1).
Для создания проекта SnowEngine требуются все файлы движка, находящиеся в директории SnowEngine\src\. Поместите папку src в любой удобный для вас каталог (не переименовывая её). Рекомендуется не использовать пути, содержащие кириллицу и символы Юникода.
Запустите файл CreateProject\creator.exe. Далее потребуется ввести некоторую информацию.
1. Путь к директории SnowEngine. Здесь требуется указать абсолютный путь к каталогу, в котором лежит папка src.
2. Путь к директории, в которой будет создано ваше решение.
3. Путь к директории SFML. Необходимо указать тот каталог, в котором расположены папки lib, include и прочие.
4. Название решения.
5. Название проекта.
При вводе данных для вставки из буфера обмена вы можете использовать сочетание клавиш Alt+Пробел, а затем нажатие Изменить->Вставить. Ну или же стандартный Ctrl+V, если вам повезло/не повезло (нужное подчеркнуть) использовать Windows 10.
После этого начнётся генерация решения. Если всё прошло успешно, программа предложит открыть его. Нажатие клавиши Y приведёт к запуску Visual Studio (если она установлена), открытию в ней решения и закрытию программы, нажатие любой другой клавиши — просто к закрытию программы.
Для использования функционала SnowEngine требуется подключить заголовочный файл: #include "SnowEngine.h".
Когда-нибудь, наверное, будет и документация.