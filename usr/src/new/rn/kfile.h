begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: kfile.h,v 4.3 85/05/01 11:42:00 lwall Exp $  *  * $Log:	kfile.h,v $  * Revision 4.3  85/05/01  11:42:00  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_define
define|#
directive|define
name|KF_GLOBAL
value|0
end_define

begin_define
define|#
directive|define
name|KF_LOCAL
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KILLFILES
end_ifdef

begin_function_decl
name|EXT
name|FILE
modifier|*
name|globkfp
name|INIT
parameter_list|(
name|Nullfp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* global article killer file */
end_comment

begin_function_decl
name|EXT
name|FILE
modifier|*
name|localkfp
name|INIT
parameter_list|(
name|Nullfp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* local (for this newsgroup) */
end_comment

begin_comment
comment|/*  article killer file */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|kfile_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|do_kfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kill_unwanted
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|edit_kfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|open_kfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|kf_append
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setthru
parameter_list|()
function_decl|;
end_function_decl

end_unit

