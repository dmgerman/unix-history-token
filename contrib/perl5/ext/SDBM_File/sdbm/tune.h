begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sdbm - ndbm work-alike hashed database library  * tuning and portability constructs [not nearly enough]  * author: oz@nexus.yorku.ca  */
end_comment

begin_define
define|#
directive|define
name|BYTESIZ
value|8
end_define

begin_comment
comment|/*  * important tuning parms (hah)  */
end_comment

begin_define
define|#
directive|define
name|SEEDUPS
end_define

begin_comment
comment|/* always detect duplicates */
end_comment

begin_define
define|#
directive|define
name|BADMESS
end_define

begin_comment
comment|/* generate a message for worst case: 				   cannot make room after SPLTMAX splits */
end_comment

begin_comment
comment|/*  * misc  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|debug
parameter_list|(
name|x
parameter_list|)
value|printf x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|debug
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

