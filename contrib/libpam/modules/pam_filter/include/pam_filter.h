begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: pam_filter.h,v 1.2 1997/02/15 19:09:09 morgan Exp $  *  * this file is associated with the Linux-PAM filter module.  * it was written by Andrew G. Morgan<morgan@parc.power.net>  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PAM_FILTER_H
end_ifndef

begin_define
define|#
directive|define
name|PAM_FILTER_H
end_define

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_comment
comment|/*  * this will fail if there is some problem with these file descriptors  * being allocated by the pam_filter Linux-PAM module. The numbers  * here are thought safe, but the filter developer should use the  * macros, as these numbers are subject to change.  *  * The APPXXX_FILENO file descriptors are the STDIN/OUT/ERR_FILENO of the  * application. The filter uses the STDIN/OUT/ERR_FILENO's to converse  * with the user, passes (modified) user input to the application via  * APPIN_FILENO, and receives application output from APPOUT_FILENO/ERR.  */
end_comment

begin_define
define|#
directive|define
name|APPIN_FILENO
value|3
end_define

begin_comment
comment|/* write here to give application input */
end_comment

begin_define
define|#
directive|define
name|APPOUT_FILENO
value|4
end_define

begin_comment
comment|/* read here to get application output */
end_comment

begin_define
define|#
directive|define
name|APPERR_FILENO
value|5
end_define

begin_comment
comment|/* read here to get application errors */
end_comment

begin_define
define|#
directive|define
name|APPTOP_FILE
value|6
end_define

begin_comment
comment|/* used by select */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

