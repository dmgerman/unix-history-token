begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CONF_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CONF_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|ACTUALLY_LKM_NOT_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|"ioconf.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_CONF_H_ */
end_comment

end_unit

