#ifndef _TOKEN_H_
#define _TOKEN_H_
#include <stddef.h>

#include "source.h"
typedef enum {
    /* 1. 特殊 Token */
    TOK_EOF = 0,  // 文件结束
    TOK_ERROR,    // 词法错误

    /* 2. 标识符与字面量 */
    TOK_IDENTIFIER,      // 标识符：main, count
    TOK_INT_LITERAL,     // 整数常量：123
    TOK_CHAR_LITERAL,    // 字符常量：'a'
    TOK_STRING_LITERAL,  // 字符串常量："hello"
    TOK_FLOAT_LITERAL,   // 浮点数常量：3.14

    /* 3. 关键字 */
    TOK_KW_VOID,      // void
    TOK_KW_CHAR,      // char
    TOK_KW_INT,       // int
    TOK_KW_RETURN,    // return
    TOK_KW_IF,        // if
    TOK_KW_ELSE,      // else
    TOK_KW_WHILE,     // while
    TOK_KW_FOR,       // for
    TOK_KW_BREAK,     // break
    TOK_KW_CONTINUE,  // continue
    TOK_KW_CONST,     // const
    TOK_KW_STATIC,    // static
    TOK_KW_FLOAT,     // float
    TOK_KW_DOUBLE,    // double

    /* 4. 算术运算符 */
    TOK_PLUS,     // +
    TOK_MINUS,    // -
    TOK_STAR,     // *
    TOK_SLASH,    // /
    TOK_PERCENT,  // %

    /* 5. 自增、自减（可选） */
    TOK_INCREMENT,  // ++
    TOK_DECREMENT,  // --

    /* 6. 赋值与比较运算符 */
    TOK_ASSIGN,  // =
    TOK_EQ,      // ==
    TOK_NE,      // !=
    TOK_LT,      // <
    TOK_LE,      // <=
    TOK_GT,      // >
    TOK_GE,      // >=

    /* 7. 逻辑运算符 */
    TOK_LOGICAL_NOT,  // !
    TOK_LOGICAL_AND,  // &&
    TOK_LOGICAL_OR,   // ||

    /* 8. 位运算符（可选） */
    TOK_BIT_AND,      // &
    TOK_BIT_OR,       // |
    TOK_BIT_XOR,      // ^
    TOK_BIT_NOT,      // ~
    TOK_SHIFT_LEFT,   // <<
    TOK_SHIFT_RIGHT,  // >>

    /* 9. 分隔符与标点 */
    TOK_LPAREN,     // (
    TOK_RPAREN,     // )
    TOK_LBRACE,     // {
    TOK_RBRACE,     // }
    TOK_LBRACKET,   // [
    TOK_RBRACKET,   // ]
    TOK_SEMICOLON,  // ;
    TOK_COMMA,      // ,
    TOK_DOT,        // .
    TOK_QUESTION,   // ?
    TOK_COLON,      // :

    /* 10. 复合赋值（可选） */
    TOK_PLUS_ASSIGN,     // +=
    TOK_MINUS_ASSIGN,    // -=
    TOK_STAR_ASSIGN,     // *=
    TOK_SLASH_ASSIGN,    // /=
    TOK_PERCENT_ASSIGN,  // %=

    /* 11. 字符串字面量（建议预留） */
    TOK_STRING_LITERAL  // "hello"
} TokenType;

typedef struct {
    TokenType type;
    SourceLoc loc;
    char* lexeme;   // 词素文本
    size_t length;  // 词素长度
} Token;
#endif