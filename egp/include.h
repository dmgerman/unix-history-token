begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* include.h */
end_comment

begin_comment
comment|/* EGP User Process, ISI 23-Jun-84 */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_comment
comment|/* init.c, egp2.c, rt_egp.c */
end_comment

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip_icmp.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_comment
comment|/* init.c */
end_comment

begin_include
include|#
directive|include
file|<net/route.h>
end_include

begin_comment
comment|/* definitions from routed */
end_comment

begin_include
include|#
directive|include
file|"trace_egp.h"
end_include

begin_include
include|#
directive|include
file|"if.h"
end_include

begin_include
include|#
directive|include
file|"rt_table.h"
end_include

begin_comment
comment|/* new definitions */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"egp.h"
end_include

begin_include
include|#
directive|include
file|"egp_param.h"
end_include

begin_comment
comment|/* used by egp.c, init.c */
end_comment

end_unit

