begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * User Space Library Functions  * ----------------------------  *  * IP checksum computation  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netatm/port.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_if.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_sap.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_sys.h>
end_include

begin_include
include|#
directive|include
file|<netatm/atm_ioctl.h>
end_include

begin_include
include|#
directive|include
file|"libatm.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"@(#) $FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Compute an IP checksum  *  * This code was taken from RFC 1071.  *  * "The following "C" code algorithm computes the checksum with an inner  * loop that sums 16 bits at a time in a 32-bit accumulator."  *  * Arguments:  *	addr	pointer to the buffer whose checksum is to be computed  *	count	number of bytes to include in the checksum  *  * Returns:  *	the computed checksum  *  */
end_comment

begin_function
name|short
name|ip_checksum
parameter_list|(
name|addr
parameter_list|,
name|count
parameter_list|)
name|char
modifier|*
name|addr
decl_stmt|;
name|int
name|count
decl_stmt|;
block|{
comment|/* Compute Internet Checksum for "count" bytes 	 * beginning at location "addr". 	 */
specifier|register
name|long
name|sum
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|count
operator|>
literal|1
condition|)
block|{
comment|/* This is the inner loop */
name|sum
operator|+=
name|ntohs
argument_list|(
operator|*
operator|(
name|unsigned
name|short
operator|*
operator|)
name|addr
argument_list|)
expr_stmt|;
name|addr
operator|+=
expr|sizeof
operator|(
name|unsigned
name|short
operator|)
expr_stmt|;
name|count
operator|-=
expr|sizeof
operator|(
name|unsigned
name|short
operator|)
expr_stmt|;
block|}
comment|/* Add left-over byte, if any */
if|if
condition|(
name|count
operator|>
literal|0
condition|)
name|sum
operator|+=
operator|*
operator|(
name|unsigned
name|char
operator|*
operator|)
name|addr
expr_stmt|;
comment|/* Fold 32-bit sum to 16 bits */
while|while
condition|(
name|sum
operator|>>
literal|16
condition|)
name|sum
operator|=
operator|(
name|sum
operator|&
literal|0xffff
operator|)
operator|+
operator|(
name|sum
operator|>>
literal|16
operator|)
expr_stmt|;
return|return
operator|(
operator|(
name|short
operator|)
operator|~
name|sum
operator|)
return|;
block|}
end_function

end_unit

