begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* policy.h - representation of security policy */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/quipu/RCS/policy.h,v 7.1 91/02/22 09:26:04 mrose Interim $  *  *  * $Log:	policy.h,v $  * Revision 7.1  91/02/22  09:26:04  mrose  * Interim 6.8  *   * Revision 7.0  90/08/24  12:11:24  mrose  * *** empty log message ***  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPUPOLICY
end_ifndef

begin_define
define|#
directive|define
name|QUIPUPOLICY
end_define

begin_include
include|#
directive|include
file|"psap.h"
end_include

begin_struct
struct|struct
name|security_policy
block|{
name|OID
name|oid
decl_stmt|;
name|int
name|p_type
decl_stmt|;
define|#
directive|define
name|POLICY_PARM_ABSENT
value|0
define|#
directive|define
name|POLICY_PARM_UNKNOWN
value|1
define|#
directive|define
name|POLICY_PARM_NUMERIC
value|2
define|#
directive|define
name|POLICY_PARM_ACCESS
value|3
union|union
block|{
name|int
name|numeric
decl_stmt|;
name|unsigned
name|access
decl_stmt|;
block|}
name|un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLPOLICY
value|((struct security_policy *) 0)
end_define

begin_define
define|#
directive|define
name|POLICY_ACCESS_DETECT
value|1
end_define

begin_define
define|#
directive|define
name|POLICY_ACCESS_READ
value|2
end_define

begin_define
define|#
directive|define
name|POLICY_ACCESS_ADD
value|4
end_define

begin_define
define|#
directive|define
name|POLICY_ACCESS_WRITE
value|8
end_define

begin_define
define|#
directive|define
name|POLICY_ACCESS_ALL
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

