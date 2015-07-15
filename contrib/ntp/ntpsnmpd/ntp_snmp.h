begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_snmp.h -- common net-snmp header includes and workaround  *		 for Autoconf-related PACKAGE_* redefinitions between  *		 net-snmp and NTP.  *  * Currently ntpsnmpd *.c files are exceptions to the rule that every .c  * file should include<config.h> before any other headers.  It would be  * ideal to rearrange its includes so that our config.h is first, but  * that is complicated by the redefinitions between our config.h and  * net-snmp/net-snmp-config.h.  */
end_comment

begin_include
include|#
directive|include
file|<net-snmp/net-snmp-config.h>
end_include

begin_include
include|#
directive|include
file|<net-snmp/net-snmp-includes.h>
end_include

begin_include
include|#
directive|include
file|<net-snmp/agent/net-snmp-agent-includes.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|PACKAGE_BUGREPORT
end_ifdef

begin_undef
undef|#
directive|undef
name|PACKAGE_BUGREPORT
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PACKAGE_NAME
end_ifdef

begin_undef
undef|#
directive|undef
name|PACKAGE_NAME
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PACKAGE_STRING
end_ifdef

begin_undef
undef|#
directive|undef
name|PACKAGE_STRING
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PACKAGE_TARNAME
end_ifdef

begin_undef
undef|#
directive|undef
name|PACKAGE_TARNAME
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PACKAGE_URL
end_ifdef

begin_undef
undef|#
directive|undef
name|PACKAGE_URL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|PACKAGE_VERSION
end_ifdef

begin_undef
undef|#
directive|undef
name|PACKAGE_VERSION
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<ntpSnmpSubagentObject.h>
end_include

begin_include
include|#
directive|include
file|<config.h>
end_include

end_unit

