begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mf.h - include file for mailbox filters */
end_comment

begin_comment
comment|/* $Id: mf.h,v 1.2 1992/05/12 22:06:04 jromine Exp $ */
end_comment

begin_include
include|#
directive|include
file|"../h/strings.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NOTOK
end_ifndef

begin_define
define|#
directive|define
name|NOTOK
value|(-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OK
end_ifndef

begin_define
define|#
directive|define
name|OK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DONE
end_ifndef

begin_define
define|#
directive|define
name|DONE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LINESIZ
value|512
end_define

begin_define
define|#
directive|define
name|MBXMODE
value|0600
end_define

begin_define
define|#
directive|define
name|TMPMODE
value|0600
end_define

begin_define
define|#
directive|define
name|OWIDTH
value|75
end_define

begin_comment
comment|/* length of a header line */
end_comment

begin_define
define|#
directive|define
name|HFROM
value|1
end_define

begin_comment
comment|/* header has From: component	 */
end_comment

begin_define
define|#
directive|define
name|HSNDR
value|2
end_define

begin_comment
comment|/* header has Sender: component  */
end_comment

begin_define
define|#
directive|define
name|HADDR
value|3
end_define

begin_comment
comment|/* header has address component	 */
end_comment

begin_define
define|#
directive|define
name|HDATE
value|4
end_define

begin_comment
comment|/* header has Date: component	 */
end_comment

begin_define
define|#
directive|define
name|HOTHR
value|5
end_define

begin_comment
comment|/* header is unimportant	 */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|adrx
block|{
name|char
modifier|*
name|text
decl_stmt|;
name|char
modifier|*
name|pers
decl_stmt|;
name|char
modifier|*
name|mbox
decl_stmt|;
name|char
modifier|*
name|host
decl_stmt|;
name|char
modifier|*
name|path
decl_stmt|;
name|char
modifier|*
name|grp
decl_stmt|;
name|int
name|ingrp
decl_stmt|;
name|char
modifier|*
name|note
decl_stmt|;
name|char
modifier|*
name|err
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/*   *    Codes returned by uucp2mmdf(), mmdf2uucp()  */
end_comment

begin_define
define|#
directive|define
name|MFOK
value|0
end_define

begin_comment
comment|/* all went well		 */
end_comment

begin_comment
comment|/* remaining codes must> DONE	 */
end_comment

begin_define
define|#
directive|define
name|MFPRM
value|2
end_define

begin_comment
comment|/* bad parameter		 */
end_comment

begin_define
define|#
directive|define
name|MFSIO
value|3
end_define

begin_comment
comment|/* stdio package went screwy	 */
end_comment

begin_define
define|#
directive|define
name|MFROM
value|4
end_define

begin_comment
comment|/* from line was bad		 */
end_comment

begin_define
define|#
directive|define
name|MFHDR
value|5
end_define

begin_comment
comment|/* headers were bad		 */
end_comment

begin_define
define|#
directive|define
name|MFTXT
value|6
end_define

begin_comment
comment|/* text was bad			 */
end_comment

begin_define
define|#
directive|define
name|MFERR
value|7
end_define

begin_comment
comment|/* I/O or system error		 */
end_comment

begin_define
define|#
directive|define
name|MFDLM
value|8
end_define

begin_comment
comment|/* Bad delimiter in MMDF file	 */
end_comment

begin_decl_stmt
name|int
name|isfrom
argument_list|()
decl_stmt|,
name|lequal
argument_list|()
decl_stmt|,
name|mfgets
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|legal_person
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|adrx
modifier|*
name|seekadrx
argument_list|()
decl_stmt|,
modifier|*
name|getadrx
argument_list|()
decl_stmt|,
modifier|*
name|uucpadrx
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

