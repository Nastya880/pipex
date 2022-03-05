# pipex
Project in school 21
#Project without bonus part: 100/100

# Best video about pipe and processes
https://www.youtube.com/watch?v=6xbLgZpOBi8

# pipe()
https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/reference/pipe?view=msvc-170 - pipe(fd) - errors:

# fork()
https://www.geeksforgeeks.org/fork-system-call/

# dup(), dup2()
https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/reference/dup-dup2?view=msvc-170

# execve()
https://docs.microsoft.com/ru-ru/cpp/c-runtime-library/reference/execve-wexecve?view=msvc-170
загружает и выполняет новый процесс, передавая ему массив указателей на аргументы командной строки и массив указателей на параметры среды.
# создание файла. Права доступа.
https://www.opennet.ru/man.shtml?topic=creat&category=2
mode всегда должен быть указан при использовании O_CREAT; во всех остальных случаях этот параметр игнорируется. creat эквивалентен open с flags, которые равны O_CREAT | O_WRONLY | O_TRUNC.  

# запуск
./pipex infile cmd1 cm2 outfile
Example: ./pipex Makefile "cat" "wc -l" outfile

# PS
Пир посоветовал использовать переменную environ для полной информации о команде
