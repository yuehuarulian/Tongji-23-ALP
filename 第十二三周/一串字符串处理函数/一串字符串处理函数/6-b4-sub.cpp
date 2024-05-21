/* 2252941 ������ ��04 */

#include <cstdio>   //NULL
//������������κ�ϵͳͷ�ļ�

/* ----- ���������κ���ʽ��ȫ�ֱ���/ȫ������/ֻ��ȫ�ֱ���/�궨��!!!!! ----- */

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��returnֻ��һ��ʾ�����ɸı� */
/***************************************************************************
  ��������
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strlen(const char* str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    const char* p1 = str;
    if (str == NULL)
        return 0;
    for (; *p1 != '\0'; p1++)
        continue;
    return p1 - str;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int len1 = tj_strlen(s1);
    int len2 = tj_strlen(s2);
    char* p1 = s1;
    const char* p2 = s2;
    if (s2 == NULL || s1 == NULL)
        return s1;
    for (; (p2 - s2) <= len2; p1++, p2++)
        *(p1 + len1) = *p2;
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char* tj_strncat(char* s1, const char* s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int len1 = tj_strlen(s1);
    int len2 = tj_strlen(s2);
    char* p1 = s1;
    const char* p2 = s2;
    if (s2 == NULL || s1 == NULL)
        return s1;
    if (len > len2)
    {
        for (; p2 - s2 <= len2; p1++, p2++)
            *(p1 + len1) = *p2;
    }
    else
    {
        for (; p2 - s2 < len; p1++, p2++)
            *(p1 + len1) = *p2;
        *(p1 + len1) = '\0';
    }
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int len2 = tj_strlen(s2);
    char* p1 = s1;
    const char* p2 = s2;
    if (s1 == NULL)
        return s1;
    if (s2 == NULL) {
        *p1 = '\0';
        return s1;
    }
    for (; p2 - s2 <= len2; p1++, p2++)
        *p1 = *p2;
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strncpy(char *s1, const char *s2, const int len)
{
    int len2 = tj_strlen(s2);
    char* p1 = s1;
    const char* p2 = s2;
    if (s1 == NULL || s2 == NULL)
        return s1;
    if (len > len2){
        for (; (p2 - s2 <= len2)&&*p2!='\0'; p1++, p2++)
            *p1 = *p2;
        //while(p2-s2<=len2&&p2)    *p1++ = *p2++;
    }
    else
    {
        for (; (p2 - s2 <= len) && *p2 != '\0'; p1++, p2++)
            *p1 = *p2;
    }
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int len1 = tj_strlen(s1);
    int len2 = tj_strlen(s2);
    const char* p1 = s1;
    const char* p2 = s2;
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;
    for (; p1 - s1 <= len1 && p1 - s1 <= len2; p1++, p2++)
    {
      /*  printf("%d ", (*p1-*p2));
        while (getchar() != '\n')
            ;*/
        if (*p1 != *p2)
            return *p1 - *p2;
        
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int len1 = tj_strlen(s1);
    int len2 = tj_strlen(s2);
    const char* p1 = s1;
    const char* p2 = s2;
    int asc1, asc2;
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;
    for (; p1 - s1 <= len1 && p1 - s1 <= len2; p1++, p2++)
    {
        asc1 = *p1;
        asc2 = *p2;
        if (asc1 >= 'A' && asc1 <= 'Z')
            asc1 += 32;
        if (asc2 >= 'A' && asc2 <= 'Z')
            asc2 += 32;
        if (asc1 != asc2)
            return asc1 - asc2;

    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int len1 = tj_strlen(s1);
    int len2 = tj_strlen(s2);
    const char* p1 = s1;
    const char* p2 = s2;
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;
    for (; p1 - s1 <= len1 && p1 - s1 <= len2 && p1 - s1 < len; p1++, p2++)
    {
        if (*p1 != *p2)
            return *p1 - *p2;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int len1 = tj_strlen(s1);
    int len2 = tj_strlen(s2);
    const char* p1 = s1;
    const char* p2 = s2;
    int asc1, asc2;
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL && s2 != NULL)
        return -1;
    if (s1 != NULL && s2 == NULL)
        return 1;
    for (; p1 - s1 <= len1 && p1 - s1 <= len2 && p1 - s1 < len; p1++, p2++)
    {
        asc1 = *p1;
        asc2 = *p2;
        if (asc1 >= 'A' && asc1 <= 'Z')
            asc1 += 32;
        if (asc2 >= 'A' && asc2 <= 'Z')
            asc2 += 32;
        if (asc1 != asc2)
            return asc1 - asc2;

    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char* tj_strupr(char* str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int len1 = tj_strlen(str);
    char* p = str;
    if (str == NULL)
        return str;
    for (; p - str < len1; p++)
    {
        if (*p >= 'a' && *p <= 'z')
            *p -= 'a' - 'A';
    }
    return str;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char* tj_strlwr(char* str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int len1 = tj_strlen(str);
    char* p = str;
    if (str == NULL)
        return str;
    for (; p - str < len1; p++)
    {
        if (*p >= 'A' && *p <= 'Z')
            *p += 'a' - 'A';
    }
    return str;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strchr(const char* str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int len1 = tj_strlen(str);
    const char* p = str;
    if (str == NULL)
        return 0;
    for (; p - str < len1; p++)
    {
        if (*p == ch)
            return p - str + 1;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strstr(const char* str, const char* substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int len1 = tj_strlen(str);
    int len2 = tj_strlen(substr);
    const char* p1 = str;
    const char* p2 = substr;
    if (str == NULL || substr == NULL)
        return 0;
    for (; p1 - str < len1; p1++)
    {
        for (p2 = substr; p2 - substr < len2 && p1 - str + p2 - substr < len1; p2++)
        {
            if (*(p1 + (p2 - substr)) != *p2)
                break;
        }
        if (p2 - substr == len2)
            return p1 - str + 1;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int len1 = tj_strlen(str);
    const char* p = str + len1-1;
    if (str == NULL)
        return 0;
    for (; p - str >= 0; p--)
    {
        if (*p == ch)
            return p - str + 1;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrstr(const char* str, const char* substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int len1 = tj_strlen(str);
    int len2 = tj_strlen(substr);
    const char* p1 = str + len1 - 1;
    const char* p2 = substr + len2 - 1;
    if (str == NULL || substr == NULL)
        return 0;
    for (; p1 - str >= 0; p1--)
    {
        for (p2 = substr + len2 - 1; p2 - substr >= 0 && p1 - str + p2 - substr >= 0; p2--)
        {
            /*printf("%c %c  ", (*(p1 + (p2 - substr))), *p2);
            while (getchar() != '\n')
                ;*/
            if (*(p1 + (p2 - substr)) != *p2)
                break;
        }
        if (p2 - substr == -1)
            return p1 - str + 1;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char* tj_strrev(char* str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int len1 = tj_strlen(str);
    char* p = str;
    char t;
    if (str == NULL)
        return str;
    for (; p - str < len1 / 2; p++)
    {
        t = *p;
        *p = *(str + len1 - 1 - (p - str));
        *(str + len1 - 1 - (p - str)) = t;
    }
    return str;
}
