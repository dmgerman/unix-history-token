begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: kfile.h,v 3.0 1991/09/09 20:18:23 davison Trn $  */
end_comment

begin_comment
comment|/* This software is Copyright 1991 by Stan Barber.   *  * Permission is hereby granted to copy, reproduce, redistribute or otherwise  * use this software as long as: there is no monetary profit gained  * specifically from the use or reproduction of this software, it is not  * sold, rented, traded or otherwise marketed, and this copyright notice is  * included prominently in any copy made.   *  * The author make no claims as to the fitness or correctness of this software  * for any use whatsoever, and it is provided as is. Any use of this software  * is at the user's own risk.   */
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
comment|/* local (for this newsgroup) file */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|EXT
name|bool
name|has_normal_kills
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag when KILLs needs rereading */
end_comment

begin_decl_stmt
name|EXT
name|bool
name|save_ids
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag when we need to write ids */
end_comment

begin_decl_stmt
name|EXT
name|ART_NUM
name|killfirst
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used as firstart when killing */
end_comment

begin_decl_stmt
name|void
name|kfile_init
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|do_kfile
name|_
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kill_unwanted
name|_
argument_list|(
operator|(
name|ART_NUM
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|edit_kfile
name|_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|open_kfile
name|_
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|kf_append
name|_
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|setthru
name|_
argument_list|(
operator|(
name|ART_NUM
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

