begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"opt_defunct.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CHILD_MAX
end_ifdef

begin_warning
warning|#
directive|warning
literal|"obsolete option CHILD_MAX - use /etc/login.conf"
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|EXTRAVNODES
end_ifdef

begin_warning
warning|#
directive|warning
literal|"obsolete option EXTRAVNODES - use `sysctl -w kern.maxvnodes=value'"
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|GATEWAY
end_ifdef

begin_warning
warning|#
directive|warning
literal|"obsolete option GATEWAY - use `sysctl -w net.inet.ip_forwarding=1'"
end_warning

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OPEN_MAX
end_ifdef

begin_warning
warning|#
directive|warning
literal|"obsolete option OPEN_MAX - use /etc/login.conf"
end_warning

begin_endif
endif|#
directive|endif
end_endif

end_unit

