#ifndef WORDS_IN_STRING_H_INCLUDED
#define WORDS_IN_STRING_H_INCLUDED

/* Структура содержащая указатель на начало слова и число его появлений.
 */
struct words_st
{
    char *word;
    int num;
};

/* Псевдоним структуры words_st.
 */
typedef struct words_st words_st;

/* Функция разделяет строку str на слова, указатели на которые и число появлений которых записываются
 * в массив структур word максимальной вместимости array_size.
 * Функция возвращает -1, если строка str или массив word не были переданы или произошла ошибка при добавлении элемента в массив.
 * Функция возвращает неотрицательное значение num_word-word в остальных случаях.
 */
int word_del (char *str, words_st *word, size_t array_size);

/* Функция вычисляет количество слов в массиве структур word размера num_different_word и максимальной вместимости array_size.
 * Функция возвращает -1, если массив word не были переданы или размер массива отрицателен или больше максимальной вместимости.
 * Функция возвращает неотрицательное значение num_all_word в остальных случаях.
 */
int all_word(const words_st *word, int num_diferent_word, size_t array_size);

#endif // WORDS_IN_STRING_H_INCLUDED
