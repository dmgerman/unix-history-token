begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * These macros are partially based on Linux-PAM's<security/_pam_macros.h>,  * which were organized by Cristian Gafton and I believe are in the public  * domain.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_PAM_MACROS_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_pam_overwrite
argument_list|)
end_if

begin_define
define|#
directive|define
name|_PAM_MACROS_H
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_define
define|#
directive|define
name|_pam_overwrite
parameter_list|(
name|x
parameter_list|)
define|\
value|memset((x), 0, strlen((x)))
end_define

begin_define
define|#
directive|define
name|_pam_drop_reply
parameter_list|(
comment|/* struct pam_response * */
name|reply
parameter_list|,
comment|/* int */
name|replies
parameter_list|)
define|\
value|do { \ 	int i; \ \ 	for (i = 0; i< (replies); i++) \ 	if ((reply)[i].resp) { \ 		_pam_overwrite((reply)[i].resp); \ 		free((reply)[i].resp); \ 	} \ 	if ((reply)) free((reply)); \ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

