begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* glob.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_glob_h_
end_ifndef

begin_define
define|#
directive|define
name|_glob_h_
value|1
end_define

begin_comment
comment|/*  $RCSfile: glob.h,v $  *  $Revision: 14020.11 $  *  $Date: 93/05/21 05:45:32 $  */
end_comment

begin_function_decl
name|char
modifier|*
modifier|*
name|glob
parameter_list|(
name|char
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|letter
parameter_list|(
name|char
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|digit
parameter_list|(
name|char
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|any
parameter_list|(
name|int
name|c
parameter_list|,
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|blklen
parameter_list|(
name|char
modifier|*
modifier|*
name|av
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|blkcpy
parameter_list|(
name|char
modifier|*
modifier|*
name|oav
parameter_list|,
name|char
modifier|*
modifier|*
name|bv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|blkfree
parameter_list|(
name|char
modifier|*
modifier|*
name|av0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|copyblk
parameter_list|(
name|char
modifier|*
modifier|*
name|v
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gethdir
parameter_list|(
name|char
modifier|*
name|home_dir
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

