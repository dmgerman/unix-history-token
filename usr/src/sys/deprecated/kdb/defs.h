begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986, 1989 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)defs.h	7.8 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * adb - string table version; common definitions  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"user.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"machine/psl.h"
end_include

begin_include
include|#
directive|include
file|"machine/pte.h"
end_include

begin_include
include|#
directive|include
file|<a.out.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_decl_stmt
name|struct
name|pcb
name|kdbpcb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* must go before redef.h */
end_comment

begin_include
include|#
directive|include
file|"redef.h"
end_include

begin_include
include|#
directive|include
file|"machine/kdbparam.h"
end_include

begin_comment
comment|/* access modes */
end_comment

begin_define
define|#
directive|define
name|RD
value|0
end_define

begin_define
define|#
directive|define
name|WT
value|1
end_define

begin_define
define|#
directive|define
name|NSP
value|0
end_define

begin_define
define|#
directive|define
name|ISP
value|1
end_define

begin_define
define|#
directive|define
name|DSP
value|2
end_define

begin_define
define|#
directive|define
name|STAR
value|4
end_define

begin_comment
comment|/*  * Symbol types, used internally in calls to findsym routine.  * One the VAX this all degenerates since I& D symbols are indistinct.  * Basically we get NSYM==0 for `=' command, ISYM==DSYM otherwise.  */
end_comment

begin_define
define|#
directive|define
name|NSYM
value|0
end_define

begin_define
define|#
directive|define
name|DSYM
value|1
end_define

begin_comment
comment|/* Data space symbol */
end_comment

begin_define
define|#
directive|define
name|ISYM
value|DSYM
end_define

begin_comment
comment|/* Instruction space symbol == DSYM on VAX */
end_comment

begin_define
define|#
directive|define
name|BKPTSET
value|1
end_define

begin_define
define|#
directive|define
name|BKPTEXEC
value|2
end_define

begin_comment
comment|/*  * setexit/reset tokens..  */
end_comment

begin_define
define|#
directive|define
name|ERROR
value|1
end_define

begin_define
define|#
directive|define
name|NEXT
value|6
end_define

begin_define
define|#
directive|define
name|SINGLE
value|7
end_define

begin_define
define|#
directive|define
name|CONTIN
value|8
end_define

begin_define
define|#
directive|define
name|PANIC
value|9
end_define

begin_define
define|#
directive|define
name|LINSIZ
value|256
end_define

begin_define
define|#
directive|define
name|MAXOFF
value|1024
end_define

begin_define
define|#
directive|define
name|MAXPOS
value|80
end_define

begin_define
define|#
directive|define
name|MAXLIN
value|256
end_define

begin_define
define|#
directive|define
name|QUOTE
value|0200
end_define

begin_define
define|#
directive|define
name|LOBYTE
value|0377
end_define

begin_define
define|#
directive|define
name|STRIP
value|0177
end_define

begin_define
define|#
directive|define
name|SP
value|' '
end_define

begin_define
define|#
directive|define
name|TB
value|'\t'
end_define

begin_define
define|#
directive|define
name|EOR
value|'\n'
end_define

begin_define
define|#
directive|define
name|CTRL
parameter_list|(
name|c
parameter_list|)
value|(c&037)
end_define

begin_define
define|#
directive|define
name|eqstr
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(strcmp(a,b)==0)
end_define

begin_typedef
typedef|typedef
name|unsigned
name|ADDR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|POS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bkpt
block|{
name|ADDR
name|loc
decl_stmt|;
name|ADDR
name|ins
decl_stmt|;
name|short
name|count
decl_stmt|;
name|short
name|initcnt
decl_stmt|;
name|short
name|flag
decl_stmt|;
define|#
directive|define
name|MAXCOM
value|64
name|char
name|comm
index|[
name|MAXCOM
index|]
decl_stmt|;
name|struct
name|bkpt
modifier|*
name|nxtbkpt
decl_stmt|;
block|}
name|BKPT
operator|,
typedef|*
name|BKPTR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|rname
decl_stmt|;
name|int
modifier|*
name|rkern
decl_stmt|;
block|}
name|REGLIST
operator|,
typedef|*
name|REGPTR
typedef|;
end_typedef

begin_decl_stmt
name|ADDR
name|maxoff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ADDR
name|localval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mkfault
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|var
index|[
literal|36
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|errflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|dot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dotinc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|adrval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|adrflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|cntval
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cntflg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* result type declarations */
end_comment

begin_function_decl
name|long
name|inkdot
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|get
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|chkget
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|bchkget
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|exform
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|BKPTR
name|scanbkpt
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|nlist
modifier|*
name|symtab
decl_stmt|,
modifier|*
name|esymtab
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|nlist
modifier|*
name|cursym
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|nlist
modifier|*
name|lookup
parameter_list|()
function_decl|;
end_function_decl

end_unit

