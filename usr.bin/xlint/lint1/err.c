begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: err.c,v 1.8 1995/10/02 17:37:00 jpo Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Jochen Pohl  * All Rights Reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Jochen Pohl for  *	The NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$NetBSD: err.c,v 1.8 1995/10/02 17:37:00 jpo Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* number of errors found */
end_comment

begin_decl_stmt
name|int
name|nerr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of syntax errors */
end_comment

begin_decl_stmt
name|int
name|sytxerr
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"lint1.h"
end_include

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|basename
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|verror
name|__P
argument_list|(
operator|(
name|int
operator|,
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|vwarning
name|__P
argument_list|(
operator|(
name|int
operator|,
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|msgs
index|[]
init|=
block|{
literal|"syntax error: empty declaration"
block|,
comment|/* 0 */
literal|"old style declaration; add int"
block|,
comment|/* 1 */
literal|"empty declaration"
block|,
comment|/* 2 */
literal|"%s declared in argument declaration list"
block|,
comment|/* 3 */
literal|"illegal type combination"
block|,
comment|/* 4 */
literal|"modifying typedef with '%s'; only qualifiers allowed"
block|,
comment|/* 5 */
literal|"use 'double' instead of 'long float'"
block|,
comment|/* 6 */
literal|"only one storage class allowed"
block|,
comment|/* 7 */
literal|"illegal storage class"
block|,
comment|/* 8 */
literal|"only register valid as formal parameter storage class"
block|,
comment|/* 9 */
literal|"duplicate '%s'"
block|,
comment|/* 10 */
literal|"bit-field initializer out of range"
block|,
comment|/* 11 */
literal|"compiler takes size of function"
block|,
comment|/* 12 */
literal|"incomplete enum type: %s"
block|,
comment|/* 13 */
literal|"compiler takes alignment of function"
block|,
comment|/* 14 */
literal|"function returns illegal type"
block|,
comment|/* 15 */
literal|"array of function is illegal"
block|,
comment|/* 16 */
literal|"null dimension"
block|,
comment|/* 17 */
literal|"illegal use of 'void'"
block|,
comment|/* 18 */
literal|"void type for %s"
block|,
comment|/* 19 */
literal|"zero or negative array dimension"
block|,
comment|/* 20 */
literal|"redeclaration of formal parameter %s"
block|,
comment|/* 21 */
literal|"incomplete or misplaced function definition"
block|,
comment|/* 22 */
literal|"undefined label %s"
block|,
comment|/* 23 */
literal|"cannot initialize function: %s"
block|,
comment|/* 24 */
literal|"cannot initialize typedef: %s"
block|,
comment|/* 25 */
literal|"cannot initialize extern declaration: %s"
block|,
comment|/* 26 */
literal|"redeclaration of %s"
block|,
comment|/* 27 */
literal|"redefinition of %s"
block|,
comment|/* 28 */
literal|"previously declared extern, becomes static: %s"
block|,
comment|/* 29 */
literal|"redeclaration of %s; ANSI C requires static"
block|,
comment|/* 30 */
literal|"incomplete structure or union %s: %s"
block|,
comment|/* 31 */
literal|"argument type defaults to 'int': %s"
block|,
comment|/* 32 */
literal|"duplicate member name: %s"
block|,
comment|/* 33 */
literal|"nonportable bit-field type"
block|,
comment|/* 34 */
literal|"illegal bit-field type"
block|,
comment|/* 35 */
literal|"illegal bit-field size"
block|,
comment|/* 36 */
literal|"zero size bit-field"
block|,
comment|/* 37 */
literal|"function illegal in structure or union"
block|,
comment|/* 38 */
literal|"illegal zero sized structure member: %s"
block|,
comment|/* 39 */
literal|"unknown size: %s"
block|,
comment|/* 40 */
literal|"illegal use of bit-field"
block|,
comment|/* 41 */
literal|"forward reference to enum type"
block|,
comment|/* 42 */
literal|"redefinition hides earlier one: %s"
block|,
comment|/* 43 */
literal|"declaration introduces new type in ANSI C: %s %s"
block|,
comment|/* 44 */
literal|"base type is really '%s %s'"
block|,
comment|/* 45 */
literal|"(%s) tag redeclared"
block|,
comment|/* 46 */
literal|"zero sized %s"
block|,
comment|/* 47 */
literal|"overflow in enumeration values: %s"
block|,
comment|/* 48 */
literal|"struct or union member must be named"
block|,
comment|/* 49 */
literal|"a function is declared as an argument: %s"
block|,
comment|/* 50 */
literal|"parameter mismatch: %d declared, %d defined"
block|,
comment|/* 51 */
literal|"cannot initialize parameter: %s"
block|,
comment|/* 52 */
literal|"declared argument %s is missing"
block|,
comment|/* 53 */
literal|"trailing ',' prohibited in enum declaration"
block|,
comment|/* 54 */
literal|"integral constant expression expected"
block|,
comment|/* 55 */
literal|"integral constant too large"
block|,
comment|/* 56 */
literal|"enumeration constant hides parameter: %s"
block|,
comment|/* 57 */
literal|"type does not match prototype: %s"
block|,
comment|/* 58 */
literal|"formal parameter lacks name: param #%d"
block|,
comment|/* 59 */
literal|"void must be sole parameter"
block|,
comment|/* 60 */
literal|"void parameter cannot have name: %s"
block|,
comment|/* 61 */
literal|"function prototype parameters must have types"
block|,
comment|/* 62 */
literal|"prototype does not match old-style definition"
block|,
comment|/* 63 */
literal|"()-less function definition"
block|,
comment|/* 64 */
literal|"%s has no named members"
block|,
comment|/* 65 */
literal|"syntax requires ';' after last struct/union member"
block|,
comment|/* 66 */
literal|"cannot return incomplete type"
block|,
comment|/* 67 */
literal|"typedef already qualified with '%s'"
block|,
comment|/* 68 */
literal|"inappropriate qualifiers with 'void'"
block|,
comment|/* 69 */
literal|"%soperand of '%s' is unsigned in ANSI C"
block|,
comment|/* 70 */
literal|"too many characters in character constant"
block|,
comment|/* 71 */
literal|"typedef declares no type name"
block|,
comment|/* 72 */
literal|"empty character constant"
block|,
comment|/* 73 */
literal|"no hex digits follow \\x"
block|,
comment|/* 74 */
literal|"overflow in hex escape"
block|,
comment|/* 75 */
literal|"character escape does not fit in character"
block|,
comment|/* 76 */
literal|"bad octal digit %c"
block|,
comment|/* 77 */
literal|"nonportable character escape"
block|,
comment|/* 78 */
literal|"dubious escape \\%c"
block|,
comment|/* 79 */
literal|"dubious escape \\%o"
block|,
comment|/* 80 */
literal|"\\a undefined in traditional C"
block|,
comment|/* 81 */
literal|"\\x undefined in traditional C"
block|,
comment|/* 82 */
literal|"storage class after type is obsolescent"
block|,
comment|/* 83 */
literal|"ANSI C requires formal parameter before '...'"
block|,
comment|/* 84 */
literal|"dubious tag declaration: %s %s"
block|,
comment|/* 85 */
literal|"automatic hides external declaration: %s"
block|,
comment|/* 86 */
literal|"static hides external declaration: %s"
block|,
comment|/* 87 */
literal|"typedef hides external declaration: %s"
block|,
comment|/* 88 */
literal|"typedef redeclared: %s"
block|,
comment|/* 89 */
literal|"inconsistent redeclaration of extern: %s"
block|,
comment|/* 90 */
literal|"declaration hides parameter: %s"
block|,
comment|/* 91 */
literal|"inconsistent redeclaration of static: %s"
block|,
comment|/* 92 */
literal|"dubious static function at block level: %s"
block|,
comment|/* 93 */
literal|"function has illegal storage class: %s"
block|,
comment|/* 94 */
literal|"declaration hides earlier one: %s"
block|,
comment|/* 95 */
literal|"cannot dereference non-pointer type"
block|,
comment|/* 96 */
literal|"suffix U is illegal in traditional C"
block|,
comment|/* 97 */
literal|"suffixes F and L are illegal in traditional C"
block|,
comment|/* 98 */
literal|"%s undefined"
block|,
comment|/* 99 */
literal|"unary + is illegal in traditional C"
block|,
comment|/* 100 */
literal|"undefined struct/union member: %s"
block|,
comment|/* 101 */
literal|"illegal member use: %s"
block|,
comment|/* 102 */
literal|"left operand of '.' must be struct/union object"
block|,
comment|/* 103 */
literal|"left operand of '->' must be pointer to struct/union"
block|,
comment|/* 104 */
literal|"non-unique member requires struct/union %s"
block|,
comment|/* 105 */
literal|"left operand of '->' must be pointer"
block|,
comment|/* 106 */
literal|"operands of '%s' have incompatible types"
block|,
comment|/* 107 */
literal|"operand of '%s' has incompatible type"
block|,
comment|/* 108 */
literal|"void type illegal in expression"
block|,
comment|/* 109 */
literal|"pointer to function is not allowed here"
block|,
comment|/* 110 */
literal|"unacceptable operand of '%s'"
block|,
comment|/* 111 */
literal|"cannot take address of bit-field"
block|,
comment|/* 112 */
literal|"cannot take address of register %s"
block|,
comment|/* 113 */
literal|"%soperand of '%s' must be lvalue"
block|,
comment|/* 114 */
literal|"%soperand of '%s' must be modifiable lvalue"
block|,
comment|/* 115 */
literal|"illegal pointer subtraction"
block|,
comment|/* 116 */
literal|"bitwise operation on signed value possibly nonportable"
block|,
comment|/* 117 */
literal|"semantics of '%s' change in ANSI C; use explicit cast"
block|,
comment|/* 118 */
literal|"conversion of '%s' to '%s' is out of range"
block|,
comment|/* 119 */
literal|"bitwise operation on signed value nonportable"
block|,
comment|/* 120 */
literal|"negative shift"
block|,
comment|/* 121 */
literal|"shift greater than size of object"
block|,
comment|/* 122 */
literal|"illegal combination of pointer and integer, op %s"
block|,
comment|/* 123 */
literal|"illegal pointer combination, op %s"
block|,
comment|/* 124 */
literal|"ANSI C forbids ordered comparisons of pointers to functions"
block|,
comment|/* 125 */
literal|"incompatible types in conditional"
block|,
comment|/* 126 */
literal|"'&' before array or function: ignored"
block|,
comment|/* 127 */
literal|"operands have incompatible pointer types, op %s"
block|,
comment|/* 128 */
literal|"expression has null effect"
block|,
comment|/* 129 */
literal|"enum type mismatch, op %s"
block|,
comment|/* 130 */
literal|"conversion to '%s' may sign-extend incorrectly"
block|,
comment|/* 131 */
literal|"conversion from '%s' may lose accuracy"
block|,
comment|/* 132 */
literal|"conversion of pointer to '%s' loses bits"
block|,
comment|/* 133 */
literal|"conversion of pointer to '%s' may lose bits"
block|,
comment|/* 134 */
literal|"possible pointer alignment problem"
block|,
comment|/* 135 */
literal|"cannot do pointer arithmetic on operand of unknown size"
block|,
comment|/* 136 */
literal|"use of incomplete enum type, op %s"
block|,
comment|/* 137 */
literal|"unknown operand size, op %s"
block|,
comment|/* 138 */
literal|"division by 0"
block|,
comment|/* 139 */
literal|"modulus by 0"
block|,
comment|/* 140 */
literal|"integer overflow detected, op %s"
block|,
comment|/* 141 */
literal|"floating point overflow detected, op %s"
block|,
comment|/* 142 */
literal|"cannot take size of incomplete type"
block|,
comment|/* 143 */
literal|"cannot take size of function"
block|,
comment|/* 144 */
literal|"cannot take size of bit-field"
block|,
comment|/* 145 */
literal|"cannot take size of void"
block|,
comment|/* 146 */
literal|"invalid cast expression"
block|,
comment|/* 147 */
literal|"improper cast of void expression"
block|,
comment|/* 148 */
literal|"illegal function"
block|,
comment|/* 149 */
literal|"argument mismatch: %d arg%s passed, %d expected"
block|,
comment|/* 150 */
literal|"void expressions may not be arguments, arg #%d"
block|,
comment|/* 151 */
literal|"argument cannot have unknown size, arg #%d"
block|,
comment|/* 152 */
literal|"argument has incompatible pointer type, arg #%d"
block|,
comment|/* 153 */
literal|"illegal combination of pointer and integer, arg #%d"
block|,
comment|/* 154 */
literal|"argument is incompatible with prototype, arg #%d"
block|,
comment|/* 155 */
literal|"enum type mismatch, arg #%d"
block|,
comment|/* 156 */
literal|"ANSI C treats constant as unsigned"
block|,
comment|/* 157 */
literal|"%s may be used before set"
block|,
comment|/* 158 */
literal|"assignment in conditional context"
block|,
comment|/* 159 */
literal|"operator '==' found where '=' was expected"
block|,
comment|/* 160 */
literal|"constant in conditional context"
block|,
comment|/* 161 */
literal|"comparision of %s with %s, op %s"
block|,
comment|/* 162 */
literal|"a cast does not yield an lvalue"
block|,
comment|/* 163 */
literal|"assignment of negative constant to unsigned type"
block|,
comment|/* 164 */
literal|"constant truncated by assignment"
block|,
comment|/* 165 */
literal|"precision lost in bit-field assignment"
block|,
comment|/* 166 */
literal|"array subscript cannot be negative: %ld"
block|,
comment|/* 167 */
literal|"array subscript cannot be> %d: %ld"
block|,
comment|/* 168 */
literal|"precedence confusion possible: parenthesize!"
block|,
comment|/* 169 */
literal|"first operand must have scalar type, op ? :"
block|,
comment|/* 170 */
literal|"assignment type mismatch"
block|,
comment|/* 171 */
literal|"too many struct/union initializers"
block|,
comment|/* 172 */
literal|"too many array initializers"
block|,
comment|/* 173 */
literal|"too many initializers"
block|,
comment|/* 174 */
literal|"initialisation of an incomplete type"
block|,
comment|/* 175 */
literal|"invalid initializer"
block|,
comment|/* 176 */
literal|"non-constant initializer"
block|,
comment|/* 177 */
literal|"initializer does not fit"
block|,
comment|/* 178 */
literal|"cannot initialize struct/union with no named member"
block|,
comment|/* 179 */
literal|"bit-field initializer does not fit"
block|,
comment|/* 180 */
literal|"{}-enclosed initializer required"
block|,
comment|/* 181 */
literal|"incompatible pointer types"
block|,
comment|/* 182 */
literal|"illegal combination of pointer and integer"
block|,
comment|/* 183 */
literal|"illegal pointer combination"
block|,
comment|/* 184 */
literal|"initialisation type mismatch"
block|,
comment|/* 185 */
literal|"bit-field initialisation is illegal in traditional C"
block|,
comment|/* 186 */
literal|"non-null byte ignored in string initializer"
block|,
comment|/* 187 */
literal|"no automatic aggregate initialization in traditional C"
block|,
comment|/* 188 */
literal|"assignment of struct/union illegal in traditional C"
block|,
comment|/* 189 */
literal|"empty array declaration: %s"
block|,
comment|/* 190 */
literal|"%s set but not used in function %s"
block|,
comment|/* 191 */
literal|"%s unused in function %s"
block|,
comment|/* 192 */
literal|"statement not reached"
block|,
comment|/* 193 */
literal|"label %s redefined"
block|,
comment|/* 194 */
literal|"case not in switch"
block|,
comment|/* 195 */
literal|"case label affected by conversion"
block|,
comment|/* 196 */
literal|"non-constant case expression"
block|,
comment|/* 197 */
literal|"non-integral case expression"
block|,
comment|/* 198 */
literal|"duplicate case in switch: %ld"
block|,
comment|/* 199 */
literal|"duplicate case in switch: %lu"
block|,
comment|/* 200 */
literal|"default outside switch"
block|,
comment|/* 201 */
literal|"duplicate default in switch"
block|,
comment|/* 202 */
literal|"case label must be of type `int' in traditional C"
block|,
comment|/* 203 */
literal|"controlling expressions must have scalar type"
block|,
comment|/* 204 */
literal|"switch expression must have integral type"
block|,
comment|/* 205 */
literal|"enumeration value(s) not handled in switch"
block|,
comment|/* 206 */
literal|"loop not entered at top"
block|,
comment|/* 207 */
literal|"break outside loop or switch"
block|,
comment|/* 208 */
literal|"continue outside loop"
block|,
comment|/* 209 */
literal|"enum type mismatch in initialisation"
block|,
comment|/* 210 */
literal|"return value type mismatch"
block|,
comment|/* 211 */
literal|"cannot return incomplete type"
block|,
comment|/* 212 */
literal|"void function %s cannot return value"
block|,
comment|/* 213 */
literal|"function %s expects to return value"
block|,
comment|/* 214 */
literal|"function implicitly declared to return int"
block|,
comment|/* 215 */
literal|"function %s has return (e); and return;"
block|,
comment|/* 216 */
literal|"function %s falls off bottom without returning value"
block|,
comment|/* 217 */
literal|"ANSI C treats constant as unsigned, op %s"
block|,
comment|/* 218 */
literal|"concatenated strings are illegal in traditional C"
block|,
comment|/* 219 */
literal|"fallthrough on case statement"
block|,
comment|/* 220 */
literal|"initialisation of unsigned with negative constant"
block|,
comment|/* 221 */
literal|"conversion of negative constant to unsigned type"
block|,
comment|/* 222 */
literal|"end-of-loop code not reached"
block|,
comment|/* 223 */
literal|"cannot recover from previous errors"
block|,
comment|/* 224 */
literal|"static function called but not defined: %s()"
block|,
comment|/* 225 */
literal|"static variable %s unused"
block|,
comment|/* 226 */
literal|"const object %s should have initializer"
block|,
comment|/* 227 */
literal|"function cannot return const or volatile object"
block|,
comment|/* 228 */
literal|"questionable conversion of function pointer"
block|,
comment|/* 229 */
literal|"nonportable character comparision, op %s"
block|,
comment|/* 230 */
literal|"argument %s unused in function %s"
block|,
comment|/* 231 */
literal|"label %s unused in function %s"
block|,
comment|/* 232 */
literal|"struct %s never defined"
block|,
comment|/* 233 */
literal|"union %s never defined"
block|,
comment|/* 234 */
literal|"enum %s never defined"
block|,
comment|/* 235 */
literal|"static function %s unused"
block|,
comment|/* 236 */
literal|"redeclaration of formal parameter %s"
block|,
comment|/* 237 */
literal|"initialisation of union is illegal in traditional C"
block|,
comment|/* 238 */
literal|"constant argument to NOT"
block|,
comment|/* 239 */
literal|"assignment of different structures"
block|,
comment|/* 240 */
literal|"dubious operation on enum, op %s"
block|,
comment|/* 241 */
literal|"combination of '%s' and '%s', op %s"
block|,
comment|/* 242 */
literal|"dubious comparision of enums, op %s"
block|,
comment|/* 243 */
literal|"illegal structure pointer combination"
block|,
comment|/* 244 */
literal|"illegal structure pointer combination, op %s"
block|,
comment|/* 245 */
literal|"dubious conversion of enum to '%s'"
block|,
comment|/* 246 */
literal|"pointer casts may be troublesome"
block|,
comment|/* 247 */
literal|"floating-point constant out of range"
block|,
comment|/* 248 */
literal|"syntax error"
block|,
comment|/* 249 */
literal|"unknown character \\%o"
block|,
comment|/* 250 */
literal|"malformed integer constant"
block|,
comment|/* 251 */
literal|"integer constant out of range"
block|,
comment|/* 252 */
literal|"unterminated character constant"
block|,
comment|/* 253 */
literal|"newline in string or char constant"
block|,
comment|/* 254 */
literal|"undefined or invalid # directive"
block|,
comment|/* 255 */
literal|"unterminated comment"
block|,
comment|/* 256 */
literal|"extra characters in lint comment"
block|,
comment|/* 257 */
literal|"unterminated string constant"
block|,
comment|/* 258 */
literal|"conversion to '%s' due to prototype, arg #%d"
block|,
comment|/* 259 */
literal|"previous declaration of %s"
block|,
comment|/* 260 */
literal|"previous definition of %s"
block|,
comment|/* 261 */
literal|"\\\" inside character constants undefined in traditional C"
block|,
comment|/* 262 */
literal|"\\? undefined in traditional C"
block|,
comment|/* 263 */
literal|"\\v undefined in traditional C"
block|,
comment|/* 264 */
literal|"%s C does not support 'long long'"
block|,
comment|/* 265 */
literal|"'long double' is illegal in traditional C"
block|,
comment|/* 266 */
literal|"shift equal to size of object"
block|,
comment|/* 267 */
literal|"variable declared inline: %s"
block|,
comment|/* 268 */
literal|"argument declared inline: %s"
block|,
comment|/* 269 */
literal|"function prototypes are illegal in traditional C"
block|,
comment|/* 270 */
literal|"switch expression must be of type `int' in traditional C"
block|,
comment|/* 271 */
literal|"empty translation unit"
block|,
comment|/* 272 */
literal|"bit-field type '%s' invalid in ANSI C"
block|,
comment|/* 273 */
literal|"ANSI C forbids comparision of %s with %s"
block|,
comment|/* 274 */
literal|"cast discards 'const' from pointer target type"
block|,
comment|/* 275 */
literal|""
block|,
comment|/* 276 */
literal|"initialisation of '%s' with '%s'"
block|,
comment|/* 277 */
literal|"combination of '%s' and '%s', arg #%d"
block|,
comment|/* 278 */
literal|"combination of '%s' and '%s' in return"
block|,
comment|/* 279 */
literal|"must be outside function: /* %s */"
block|,
comment|/* 280 */
literal|"duplicate use of /* %s */"
block|,
comment|/* 281 */
literal|"must precede function definition: /* %s */"
block|,
comment|/* 282 */
literal|"argument number mismatch with directive: /* %s */"
block|,
comment|/* 283 */
literal|"fallthrough on default statement"
block|,
comment|/* 284 */
literal|"prototype declaration"
block|,
comment|/* 285 */
literal|"function definition is not a prototype"
block|,
comment|/* 286 */
literal|"function declaration is not a prototype"
block|,
comment|/* 287 */
literal|"dubious use of /* VARARGS */ with /* %s */"
block|,
comment|/* 288 */
literal|"can't be used together: /* PRINTFLIKE */ /* SCANFLIKE */"
block|,
comment|/* 289 */
literal|"static function %s declared but not defined"
block|,
comment|/* 290 */
literal|"invalid multibyte character"
block|,
comment|/* 291 */
literal|"cannot concatenate wide and regular string literals"
block|,
comment|/* 292 */
literal|"argument %d must be 'char *' for PRINTFLIKE/SCANFLIKE"
block|,
comment|/* 293 */
literal|"multi-character character constant"
block|,
comment|/* 294 */
literal|"conversion of '%s' to '%s' is out of range, arg #%d"
block|,
comment|/* 295 */
literal|"conversion of negative constant to unsigned type, arg #%d"
block|,
comment|/* 296 */
literal|"conversion to '%s' may sign-extend incorrectly, arg #%d"
block|,
comment|/* 297 */
literal|"conversion from '%s' may lose accuracy, arg #%d"
block|,
comment|/* 298 */
literal|"prototype does not match old style definition, arg #%d"
block|,
comment|/* 299 */
literal|"old style definition"
block|,
comment|/* 300 */
literal|"array of incomplete type"
block|,
comment|/* 301 */
literal|"%s returns pointer to automatic object"
block|,
comment|/* 302 */
literal|"ANSI C forbids conversion of %s to %s"
block|,
comment|/* 303 */
literal|"ANSI C forbids conversion of %s to %s, arg #%d"
block|,
comment|/* 304 */
literal|"ANSI C forbids conversion of %s to %s, op %s"
block|,
comment|/* 305 */
literal|"constant truncated by conversion, op %s"
block|,
comment|/* 306 */
literal|"static variable %s set but not used"
block|,
comment|/* 307 */
literal|""
block|,
comment|/* 308 */
literal|"extra bits set to 0 in conversion of '%s' to '%s', op %s"
block|,
comment|/* 309 */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * If Fflag is not set basename() returns a pointer to the last  * component of the path, otherwise it returns the argument.  */
end_comment

begin_function
specifier|static
specifier|const
name|char
modifier|*
name|basename
parameter_list|(
name|path
parameter_list|)
specifier|const
name|char
modifier|*
name|path
decl_stmt|;
block|{
specifier|const
name|char
modifier|*
name|cp
decl_stmt|,
modifier|*
name|cp1
decl_stmt|,
modifier|*
name|cp2
decl_stmt|;
if|if
condition|(
name|Fflag
condition|)
return|return
operator|(
name|path
operator|)
return|;
name|cp
operator|=
name|cp1
operator|=
name|cp2
operator|=
name|path
expr_stmt|;
while|while
condition|(
operator|*
name|cp
operator|!=
literal|'\0'
condition|)
block|{
if|if
condition|(
operator|*
name|cp
operator|++
operator|==
literal|'/'
condition|)
block|{
name|cp2
operator|=
name|cp1
expr_stmt|;
name|cp1
operator|=
name|cp
expr_stmt|;
block|}
block|}
return|return
operator|(
operator|*
name|cp1
operator|==
literal|'\0'
condition|?
name|cp2
else|:
name|cp1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|verror
parameter_list|(
name|n
parameter_list|,
name|ap
parameter_list|)
name|int
name|n
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
block|{
specifier|const
name|char
modifier|*
name|fn
decl_stmt|;
name|fn
operator|=
name|basename
argument_list|(
name|curr_pos
operator|.
name|p_file
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s:%d: "
argument_list|,
name|fn
argument_list|,
name|curr_pos
operator|.
name|p_line
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|vprintf
argument_list|(
name|msgs
index|[
name|n
index|]
argument_list|,
name|ap
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|nerr
operator|++
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|vwarning
parameter_list|(
name|n
parameter_list|,
name|ap
parameter_list|)
name|int
name|n
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
block|{
specifier|const
name|char
modifier|*
name|fn
decl_stmt|;
if|if
condition|(
name|nowarn
condition|)
comment|/* this warning is suppressed by a LINTED comment */
return|return;
name|fn
operator|=
name|basename
argument_list|(
name|curr_pos
operator|.
name|p_file
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s:%d: warning: "
argument_list|,
name|fn
argument_list|,
name|curr_pos
operator|.
name|p_line
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|vprintf
argument_list|(
name|msgs
index|[
name|n
index|]
argument_list|,
name|ap
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
ifdef|#
directive|ifdef
name|__STDC__
name|error
argument_list|(
name|int
name|n
argument_list|,
operator|...
argument_list|)
else|#
directive|else
name|error
argument_list|(
name|n
argument_list|,
name|va_alist
argument_list|)
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_macro
name|va_dcl
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
name|va_list
name|ap
decl_stmt|;
ifdef|#
directive|ifdef
name|__STDC__
name|va_start
argument_list|(
name|ap
argument_list|,
name|n
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|verror
argument_list|(
name|n
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
name|void
ifdef|#
directive|ifdef
name|__STDC__
name|lerror
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
function|lerror
parameter_list|(
name|msg
parameter_list|,
name|va_alist
parameter_list|)
specifier|const
name|char
modifier|*
name|msg
decl_stmt|;
function|va_dcl
endif|#
directive|endif
block|{
name|va_list
name|ap
decl_stmt|;
specifier|const
name|char
modifier|*
name|fn
decl_stmt|;
ifdef|#
directive|ifdef
name|__STDC__
name|va_start
argument_list|(
name|ap
argument_list|,
name|msg
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|fn
operator|=
name|basename
argument_list|(
name|curr_pos
operator|.
name|p_file
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s:%d: lint error: "
argument_list|,
name|fn
argument_list|,
name|curr_pos
operator|.
name|p_line
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|vfprintf
argument_list|(
name|stderr
argument_list|,
name|msg
argument_list|,
name|ap
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|void
ifdef|#
directive|ifdef
name|__STDC__
name|warning
argument_list|(
name|int
name|n
argument_list|,
operator|...
argument_list|)
else|#
directive|else
name|warning
argument_list|(
name|n
argument_list|,
name|va_alist
argument_list|)
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_macro
name|va_dcl
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
name|va_list
name|ap
decl_stmt|;
ifdef|#
directive|ifdef
name|__STDC__
name|va_start
argument_list|(
name|ap
argument_list|,
name|n
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|vwarning
argument_list|(
name|n
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
name|void
ifdef|#
directive|ifdef
name|__STDC__
name|message
parameter_list|(
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
function|message
parameter_list|(
name|n
parameter_list|,
name|va_alist
parameter_list|)
name|int
name|n
decl_stmt|;
function|va_dcl
endif|#
directive|endif
block|{
name|va_list
name|ap
decl_stmt|;
specifier|const
name|char
modifier|*
name|fn
decl_stmt|;
ifdef|#
directive|ifdef
name|__STDC__
name|va_start
argument_list|(
name|ap
argument_list|,
name|n
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|fn
operator|=
name|basename
argument_list|(
name|curr_pos
operator|.
name|p_file
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s:%d: "
argument_list|,
name|fn
argument_list|,
name|curr_pos
operator|.
name|p_line
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|vprintf
argument_list|(
name|msgs
index|[
name|n
index|]
argument_list|,
name|ap
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
ifdef|#
directive|ifdef
name|__STDC__
name|gnuism
parameter_list|(
name|int
name|n
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
function|gnuism
parameter_list|(
name|n
parameter_list|,
name|va_alist
parameter_list|)
name|int
name|n
decl_stmt|;
function|va_dcl
endif|#
directive|endif
block|{
name|va_list
name|ap
decl_stmt|;
name|int
name|msg
decl_stmt|;
ifdef|#
directive|ifdef
name|__STDC__
name|va_start
argument_list|(
name|ap
argument_list|,
name|n
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|sflag
operator|&&
operator|!
name|gflag
condition|)
block|{
name|verror
argument_list|(
name|n
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|msg
operator|=
literal|1
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|sflag
operator|&&
name|gflag
condition|)
block|{
name|msg
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|vwarning
argument_list|(
name|n
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|msg
operator|=
literal|1
expr_stmt|;
block|}
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
operator|(
name|msg
operator|)
return|;
block|}
end_function

end_unit

