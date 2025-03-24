#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_COUNT 1000
#define PASSWORD_LENGTH 20

// Функция для генерации паролей
void generate_passwords(const char *name, const char *birth_year, FILE *file) {
    char password[PASSWORD_LENGTH + 1];

    // Генерация различных комбинаций паролей
    fprintf(file, "%s\n", name); // Имя
    fprintf(file, "%s%s\n", name, birth_year); // имя + год
    fprintf(file, "%s%s\n", birth_year, name); // год + имя
    fprintf(file, "%s%s06\n", name, birth_year); // имя + год + 06
    fprintf(file, "%s6\n", name); // имя + 6
    fprintf(file, "%s%s\n", birth_year, name + 1); // год + имя без первой буквы
    fprintf(file, "%s0%s\n", birth_year, name); // 0 + год + имя
    fprintf(file, "%s0%s\n", name, birth_year + 2); // имя + последние 2 цифры года

    // Генерация случайных паролей
    for (int i = 0; i < PASSWORD_COUNT - 8; i++) {
        snprintf(password, PASSWORD_LENGTH + 1, "%s%02d", name, rand() % 100); // имя + случайные 2 цифры
        fprintf(file, "%s\n", password);
    }
}

int main() {
    srand(time(NULL)); // Инициализация генератора случайных чисел
    
    char name[50];
    char birth_year[5];

    // Запрос имени и года рождения
    printf("Введите ваше имя: ");
    scanf("%49s", name);
    printf("Введите ваш год рождения: ");
    scanf("%4s", birth_year);

    // Открытие файла для записи
    FILE *file = fopen("password.txt", "w");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return 1;
    }

    // Генерация паролей и запись в файл
    generate_passwords(name, birth_year, file);

    fclose(file); // Закрытие файла
    printf("Пароли успешно записаны в файл password.txt\n");

    return 0;
}
                            
