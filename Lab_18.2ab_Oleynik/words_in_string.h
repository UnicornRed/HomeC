#ifndef WORDS_IN_STRING_H_INCLUDED
#define WORDS_IN_STRING_H_INCLUDED

/* ��������� ���������� ��������� �� ������ ����� � ����� ��� ���������.
 */
struct words_st
{
    char *word;
    int num;
};

/* ��������� ��������� words_st.
 */
typedef struct words_st words_st;

/* ������� ��������� ������ str �� �����, ��������� �� ������� � ����� ��������� ������� ������������
 * � ������ �������� word ������������ ����������� array_size.
 * ������� ���������� -1, ���� ������ str ��� ������ word �� ���� �������� ��� ��������� ������ ��� ���������� �������� � ������.
 * ������� ���������� ��������������� �������� num_word-word � ��������� �������.
 */
int word_del (char *str, words_st *word, size_t array_size);

/* ������� ��������� ���������� ���� � ������� �������� word ������� num_different_word � ������������ ����������� array_size.
 * ������� ���������� -1, ���� ������ word �� ���� �������� ��� ������ ������� ����������� ��� ������ ������������ �����������.
 * ������� ���������� ��������������� �������� num_all_word � ��������� �������.
 */
int all_word(const words_st *word, int num_diferent_word, size_t array_size);

#endif // WORDS_IN_STRING_H_INCLUDED
