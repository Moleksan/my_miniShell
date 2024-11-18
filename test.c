#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *input;

    // Бесконечный цикл для работы с вводом пользователя
    while (1) {
        // Отображение приглашения и чтение строки
        input = readline("minishell> ");

        // Проверка на EOF (ctrl+D)
        if (!input) {
            printf("\nExiting minishell\n");
            break;
        }

        // Проверка команды выхода
        if (strcmp(input, "exit") == 0) {
            free(input);
            printf("Goodbye!\n");
            break;
        }

        // Если строка не пустая, добавляем ее в историю команд
        if (*input) {
            add_history(input);
        }

        // Вывод введенной строки (для демонстрации)
        printf("You entered: %s\n", input);

        // Освобождение памяти, выделенной для строки
        free(input);
    }

    return 0;
}

