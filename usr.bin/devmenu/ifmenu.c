begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1995 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby  * granted, provided that both the above copyright notice and this  * permission notice appear in all copies, that both the above  * copyright notice and this permission notice appear in all  * supporting documentation, and that the name of M.I.T. not be used  * in advertising or publicity pertaining to distribution of the  * software without specific, written prior permission.  M.I.T. makes  * no representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied  * warranty.  *   * THIS SOFTWARE IS PROVIDED BY M.I.T. ``AS IS''.  M.I.T. DISCLAIMS  * ALL EXPRESS OR IMPLIED WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT  * SHALL M.I.T. BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * ifmenu - present a menu of network interfaces  *  * Garrett A. Wollman, April 1995  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/devconf.h>
end_include

begin_include
include|#
directive|include
file|"devmenu.h"
end_include

begin_comment
comment|/*  * This is provided in a separate file so that, in the future, non-physical  * network interfaces might be added as well.  */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|devmenu_netif
parameter_list|(
specifier|const
name|char
modifier|*
name|title
parameter_list|,
specifier|const
name|char
modifier|*
name|hfile
parameter_list|,
name|char
modifier|*
modifier|*
name|devnames
parameter_list|)
block|{
return|return
name|devmenu_common
argument_list|(
name|title
argument_list|,
name|hfile
argument_list|,
name|devnames
argument_list|,
literal|"Select a network interface"
argument_list|,
literal|"No network interfaces available"
argument_list|,
name|DC_CLS_NETIF
argument_list|)
return|;
block|}
end_function

end_unit

