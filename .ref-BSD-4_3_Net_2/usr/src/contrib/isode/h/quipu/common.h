begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* common.h - */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/common.h,v 7.2 91/02/22 09:25:28 mrose Interim $  *  *  * $Log:	common.h,v $  * Revision 7.2  91/02/22  09:25:28  mrose  * Interim 6.8  *   * Revision 7.1  90/11/20  15:30:29  mrose  * cjr  *   * Revision 7.0  89/11/23  21:56:25  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COMH
end_ifndef

begin_define
define|#
directive|define
name|COMH
end_define

begin_include
include|#
directive|include
file|"quipu/attrvalue.h"
end_include

begin_include
include|#
directive|include
file|"quipu/dsp.h"
end_include

begin_include
include|#
directive|include
file|"quipu/commonarg.h"
end_include

begin_include
include|#
directive|include
file|"quipu/bind.h"
end_include

begin_include
include|#
directive|include
file|"quipu/read.h"
end_include

begin_include
include|#
directive|include
file|"quipu/compare.h"
end_include

begin_include
include|#
directive|include
file|"quipu/abandon.h"
end_include

begin_include
include|#
directive|include
file|"quipu/list.h"
end_include

begin_include
include|#
directive|include
file|"quipu/ds_search.h"
end_include

begin_include
include|#
directive|include
file|"quipu/add.h"
end_include

begin_include
include|#
directive|include
file|"quipu/modify.h"
end_include

begin_include
include|#
directive|include
file|"quipu/modifyrdn.h"
end_include

begin_include
include|#
directive|include
file|"quipu/remove.h"
end_include

begin_include
include|#
directive|include
file|"quipu/ds_error.h"
end_include

begin_typedef
typedef|typedef
struct|struct
name|simple_creds
block|{
name|DN
name|usc_dn
decl_stmt|;
name|int
name|usc_passwd_len
decl_stmt|;
name|char
modifier|*
name|usc_passwd
decl_stmt|;
name|char
modifier|*
name|usc_time1
decl_stmt|;
name|char
modifier|*
name|usc_time2
decl_stmt|;
block|}
name|USC
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

