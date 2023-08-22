#ifndef WORD_DEL_H_INCLUDED
#define WORD_DEL_H_INCLUDED

/* Функция разделяет строку str на слова, указатели на которые записываются в массив word.
 * Функция возвращает -1, если строка str или массив word не были переданы.
 * Функция возвращает положительное значение num_word в остальных случаях.
 */
int word_del (char *str, char **word);

#endif // WORD_DEL_H_INCLUDED
