begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 Keith Muller.  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego.  *  * %sccs.include.redist.c%  *  *      @(#)pr.h	5.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * parameter defaults  */
end_comment

begin_define
define|#
directive|define
name|CLCNT
value|1
end_define

begin_define
define|#
directive|define
name|INCHAR
value|'\t'
end_define

begin_define
define|#
directive|define
name|INGAP
value|8
end_define

begin_define
define|#
directive|define
name|OCHAR
value|'\t'
end_define

begin_define
define|#
directive|define
name|OGAP
value|8
end_define

begin_define
define|#
directive|define
name|LINES
value|66
end_define

begin_define
define|#
directive|define
name|NMWD
value|5
end_define

begin_define
define|#
directive|define
name|NMCHAR
value|'\t'
end_define

begin_define
define|#
directive|define
name|SCHAR
value|'\t'
end_define

begin_define
define|#
directive|define
name|PGWD
value|72
end_define

begin_define
define|#
directive|define
name|SPGWD
value|512
end_define

begin_comment
comment|/*  * misc default values  */
end_comment

begin_define
define|#
directive|define
name|HDFMT
value|"%s %s Page %d\n\n\n"
end_define

begin_define
define|#
directive|define
name|HEADLEN
value|5
end_define

begin_define
define|#
directive|define
name|TAILLEN
value|5
end_define

begin_define
define|#
directive|define
name|TIMEFMT
value|"%b %e %H:%M %Y"
end_define

begin_define
define|#
directive|define
name|FNAME
value|""
end_define

begin_define
define|#
directive|define
name|LBUF
value|8192
end_define

begin_define
define|#
directive|define
name|HDBUF
value|512
end_define

begin_comment
comment|/*  * structure for vertical columns. Used to balance cols on last page  */
end_comment

begin_struct
struct|struct
name|vcol
block|{
name|char
modifier|*
name|pt
decl_stmt|;
comment|/* ptr to col */
name|int
name|cnt
decl_stmt|;
comment|/* char count */
block|}
struct|;
end_struct

end_unit

