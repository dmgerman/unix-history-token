begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ex_re.h	7.3 (Berkeley) 5/31/85  */
end_comment

begin_comment
comment|/*  * Regular expression definitions.  * The regular expressions in ex are similar to those in ed,  * with the addition of the word boundaries from Toronto ed  * and allowing character classes to have [a-b] as in the shell.  * The numbers for the nodes below are spaced further apart then  * necessary because I at one time partially put in + and | (one or  * more and alternation.)  */
end_comment

begin_struct
struct|struct
name|regexp
block|{
name|char
name|Expbuf
index|[
name|ESIZE
operator|+
literal|2
index|]
decl_stmt|;
name|bool
name|Circfl
decl_stmt|;
name|short
name|Nbra
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * There are three regular expressions here, the previous (in re),  * the previous substitute (in subre) and the previous scanning (in scanre).  * It would be possible to get rid of "re" by making it a stack parameter  * to the appropriate routines.  */
end_comment

begin_decl_stmt
name|var
name|struct
name|regexp
name|re
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last re */
end_comment

begin_decl_stmt
name|var
name|struct
name|regexp
name|scanre
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last scanning re */
end_comment

begin_decl_stmt
name|var
name|struct
name|regexp
name|subre
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last substitute re */
end_comment

begin_comment
comment|/*  * Defining circfl and expbuf like this saves us from having to change  * old code in the ex_re.c stuff.  */
end_comment

begin_define
define|#
directive|define
name|expbuf
value|re.Expbuf
end_define

begin_define
define|#
directive|define
name|circfl
value|re.Circfl
end_define

begin_define
define|#
directive|define
name|nbra
value|re.Nbra
end_define

begin_comment
comment|/*  * Since the phototypesetter v7-epsilon  * C compiler doesn't have structure assignment...  */
end_comment

begin_define
define|#
directive|define
name|savere
parameter_list|(
name|a
parameter_list|)
value|copy(&a,&re, sizeof (struct regexp))
end_define

begin_define
define|#
directive|define
name|resre
parameter_list|(
name|a
parameter_list|)
value|copy(&re,&a, sizeof (struct regexp))
end_define

begin_comment
comment|/*  * Definitions for substitute  */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|braslist
index|[
name|NBRA
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Starts of \(\)'ed text in lhs */
end_comment

begin_decl_stmt
name|var
name|char
modifier|*
name|braelist
index|[
name|NBRA
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Ends... */
end_comment

begin_decl_stmt
name|var
name|char
name|rhsbuf
index|[
name|RHSSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Rhs of last substitute */
end_comment

begin_comment
comment|/*  * Definitions of codes for the compiled re's.  * The re algorithm is described in a paper  * by K. Thompson in the CACM about 10 years ago  * and is the same as in ed.  */
end_comment

begin_define
define|#
directive|define
name|STAR
value|1
end_define

begin_define
define|#
directive|define
name|CBRA
value|1
end_define

begin_define
define|#
directive|define
name|CDOT
value|4
end_define

begin_define
define|#
directive|define
name|CCL
value|8
end_define

begin_define
define|#
directive|define
name|NCCL
value|12
end_define

begin_define
define|#
directive|define
name|CDOL
value|16
end_define

begin_define
define|#
directive|define
name|CEOFC
value|17
end_define

begin_define
define|#
directive|define
name|CKET
value|18
end_define

begin_define
define|#
directive|define
name|CCHR
value|20
end_define

begin_define
define|#
directive|define
name|CBRC
value|24
end_define

begin_define
define|#
directive|define
name|CLET
value|25
end_define

end_unit

