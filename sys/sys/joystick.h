begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_JOYSTICK_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_JOYSTICK_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_struct
struct|struct
name|joystick
block|{
name|int
name|x
decl_stmt|;
name|int
name|y
decl_stmt|;
name|int
name|b1
decl_stmt|;
name|int
name|b2
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|JOY_SETTIMEOUT
value|_IOW('J', 1, int)
end_define

begin_comment
comment|/* set timeout */
end_comment

begin_define
define|#
directive|define
name|JOY_GETTIMEOUT
value|_IOR('J', 2, int)
end_define

begin_comment
comment|/* get timeout */
end_comment

begin_define
define|#
directive|define
name|JOY_SET_X_OFFSET
value|_IOW('J', 3, int)
end_define

begin_comment
comment|/* set offset on X-axis */
end_comment

begin_define
define|#
directive|define
name|JOY_SET_Y_OFFSET
value|_IOW('J', 4, int)
end_define

begin_comment
comment|/* set offset on X-axis */
end_comment

begin_define
define|#
directive|define
name|JOY_GET_X_OFFSET
value|_IOR('J', 5, int)
end_define

begin_comment
comment|/* get offset on X-axis */
end_comment

begin_define
define|#
directive|define
name|JOY_GET_Y_OFFSET
value|_IOR('J', 6, int)
end_define

begin_comment
comment|/* get offset on Y-axis */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_JOYSTICK_H_ */
end_comment

end_unit

