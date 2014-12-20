begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_filegen.h,v 3.9 1996/12/01 16:02:45 kardel Exp  *  * definitions for NTP file generations support  *  *  * Copyright (C) 1992, 1996 by Rainer Pruy  * Friedrich-Alexander Universitaet Erlangen-Nuernberg, Germany  *  * This code may be modified and used freely  * provided the credits remain intact.  */
end_comment

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_comment
comment|/*  * supported file generation types  */
end_comment

begin_define
define|#
directive|define
name|FILEGEN_NONE
value|255
end_define

begin_comment
comment|/* no generations - use plain file name */
end_comment

begin_define
define|#
directive|define
name|FILEGEN_PID
value|1
end_define

begin_comment
comment|/* one filegen per process incarnation */
end_comment

begin_define
define|#
directive|define
name|FILEGEN_DAY
value|2
end_define

begin_comment
comment|/* one filegen per day */
end_comment

begin_define
define|#
directive|define
name|FILEGEN_WEEK
value|3
end_define

begin_comment
comment|/* one filegen per week */
end_comment

begin_define
define|#
directive|define
name|FILEGEN_MONTH
value|4
end_define

begin_comment
comment|/* one filegen per month */
end_comment

begin_define
define|#
directive|define
name|FILEGEN_YEAR
value|5
end_define

begin_comment
comment|/* one filegen per year */
end_comment

begin_define
define|#
directive|define
name|FILEGEN_AGE
value|6
end_define

begin_comment
comment|/* change filegen each FG_AGE_SECS */
end_comment

begin_comment
comment|/*  * supported file generation flags  */
end_comment

begin_define
define|#
directive|define
name|FGEN_FLAG_LINK
value|0x01
end_define

begin_comment
comment|/* make a link to base name */
end_comment

begin_define
define|#
directive|define
name|FGEN_FLAG_ENABLED
value|0x80
end_define

begin_comment
comment|/* set this to really create files	  */
end_comment

begin_comment
comment|/* without this, open is suppressed */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|filegen_tag
block|{
name|FILE
modifier|*
name|fp
decl_stmt|;
comment|/* file referring to current generation */
name|char
modifier|*
name|dir
decl_stmt|;
comment|/* currently always statsdir */
name|char
modifier|*
name|fname
decl_stmt|;
comment|/* filename prefix of generation file */
comment|/* must be malloced, will be fed to free() */
name|u_long
name|id_lo
decl_stmt|;
comment|/* lower bound of ident value */
name|u_long
name|id_hi
decl_stmt|;
comment|/* upper bound of ident value */
name|u_char
name|type
decl_stmt|;
comment|/* type of file generation */
name|u_char
name|flag
decl_stmt|;
comment|/* flags modifying processing of file generation */
block|}
name|FILEGEN
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|filegen_setup
parameter_list|(
name|FILEGEN
modifier|*
parameter_list|,
name|u_int32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|filegen_config
parameter_list|(
name|FILEGEN
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|filegen_statsdir
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILEGEN
modifier|*
name|filegen_get
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|filegen_register
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|FILEGEN
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_function_decl
specifier|extern
name|void
name|filegen_unregister
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

