begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* usual BSD style copyright here */
end_comment

begin_comment
comment|/* Written by Julian Elischer (julian@dialix.oz.au)*/
end_comment

begin_comment
comment|/*  * $Id:$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DEVFSECT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DEVFSECT_H_
value|1
end_define

begin_function_decl
name|void
modifier|*
name|dev_add
parameter_list|(
name|char
modifier|*
name|path
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|funct
parameter_list|,
name|int
name|minor
parameter_list|,
name|int
name|chrblk
parameter_list|,
name|uid_t
name|uid
parameter_list|,
name|gid_t
name|gid
parameter_list|,
name|int
name|perms
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|dev_link
parameter_list|(
name|char
modifier|*
name|path
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|original
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* the result of a previous dev_link 					or dev_add operation */
end_comment

begin_define
define|#
directive|define
name|DV_CHR
value|0
end_define

begin_define
define|#
directive|define
name|DV_BLK
value|1
end_define

begin_define
define|#
directive|define
name|DV_DEV
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_SYS_DEVFSECT_H_*/
end_comment

end_unit

