begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_comment
comment|/*  * Character constants and bits  *  * The editor uses the QUOTE bit as a flag to pass on with characters  * e.g. to the putchar routine.  The editor never uses a simple char variable.  * Only arrays of and pointers to characters are used and parameters and  * registers are never declared character.  */
end_comment

begin_define
define|#
directive|define
name|QUOTE
value|0200
end_define

begin_define
define|#
directive|define
name|TRIM
value|0177
end_define

begin_define
define|#
directive|define
name|CTRL
parameter_list|(
name|c
parameter_list|)
value|('c'& 037)
end_define

begin_define
define|#
directive|define
name|NL
value|CTRL(j)
end_define

begin_define
define|#
directive|define
name|CR
value|CTRL(m)
end_define

begin_define
define|#
directive|define
name|DELETE
value|0177
end_define

begin_comment
comment|/* See also ATTN, QUIT in ex_tune.h */
end_comment

begin_define
define|#
directive|define
name|ESCAPE
value|033
end_define

end_unit

