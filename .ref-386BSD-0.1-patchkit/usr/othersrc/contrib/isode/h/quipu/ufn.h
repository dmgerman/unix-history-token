begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ufn.h - user-friendly naming routines */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/ufn.h,v 7.1 91/02/22 09:26:09 mrose Interim $  *  *  * $Log:	ufn.h,v $  * Revision 7.1  91/02/22  09:26:09  mrose  * Interim 6.8  *   * Revision 7.0  90/06/11  09:57:41  mrose  * *** empty log message ***  *   */
end_comment

begin_comment
comment|/*  *                                NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QUIPUUFN_
end_ifndef

begin_define
define|#
directive|define
name|_QUIPUUFN_
end_define

begin_include
include|#
directive|include
file|"quipu/util.h"
end_include

begin_include
include|#
directive|include
file|"quipu/name.h"
end_include

begin_include
include|#
directive|include
file|"quipu/entry.h"
end_include

begin_typedef
typedef|typedef
name|struct
name|dn_seq
modifier|*
name|DNS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLDNS
value|((struct dn_seq *) NULL)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_envlist
block|{
name|DNS
name|Dns
decl_stmt|;
name|int
name|Upper
decl_stmt|;
name|int
name|Lower
decl_stmt|;
name|struct
name|_envlist
modifier|*
name|Next
decl_stmt|;
block|}
typedef|*
name|envlist
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLEL
value|((envlist) NULL)
end_define

begin_function_decl
name|envlist
name|read_envlist
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
name|ufn_notify
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ufn_flags
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|UFN_NULL
value|0x00
end_define

begin_define
define|#
directive|define
name|UFN_APPROX
value|0x01
end_define

begin_define
define|#
directive|define
name|UFN_WILDHEAD
value|0x02
end_define

begin_define
define|#
directive|define
name|UFN_ALL
value|(UFN_APPROX | UFN_WILDHEAD)
end_define

begin_function_decl
name|int
name|ufn_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ufn_match
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

