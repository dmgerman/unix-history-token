begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ichsmb_var.h  *  * Copyright (c) 2000 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Archie Cobbs<archie@freebsd.org>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ICHSMB_ICHSMB_VAR_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ICHSMB_ICHSMB_VAR_H
end_define

begin_include
include|#
directive|include
file|"smbus_if.h"
end_include

begin_comment
comment|/* Per-device private info */
end_comment

begin_struct
struct|struct
name|ichsmb_softc
block|{
comment|/* Device/bus stuff */
name|device_t
name|dev
decl_stmt|;
comment|/* this device */
name|struct
name|resource
modifier|*
name|io_res
decl_stmt|;
comment|/* i/o port resource */
name|int
name|io_rid
decl_stmt|;
comment|/* i/o port bus id */
name|bus_space_tag_t
name|io_bst
decl_stmt|;
comment|/* bus space tag */
name|bus_space_handle_t
name|io_bsh
decl_stmt|;
comment|/* bus space handle */
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
comment|/* interrupt resource */
name|int
name|irq_rid
decl_stmt|;
comment|/* interrupt bus id */
name|void
modifier|*
name|irq_handle
decl_stmt|;
comment|/* handle for interrupt code */
comment|/* Device state */
name|int
name|ich_cmd
decl_stmt|;
comment|/* ich command, or -1 */
name|int
name|smb_error
decl_stmt|;
comment|/* result of smb command */
name|int
name|block_count
decl_stmt|;
comment|/* count for block read/write */
name|int
name|block_index
decl_stmt|;
comment|/* index for block read/write */
name|u_char
name|block_write
decl_stmt|;
comment|/* 0=read, 1=write */
name|u_char
name|block_data
index|[
literal|32
index|]
decl_stmt|;
comment|/* block read/write data */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ichsmb_softc
modifier|*
name|sc_p
typedef|;
end_typedef

begin_comment
comment|/* SMBus methods */
end_comment

begin_decl_stmt
specifier|extern
name|smbus_callback_t
name|ichsmb_callback
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|smbus_quick_t
name|ichsmb_quick
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|smbus_sendb_t
name|ichsmb_sendb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|smbus_recvb_t
name|ichsmb_recvb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|smbus_writeb_t
name|ichsmb_writeb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|smbus_writew_t
name|ichsmb_writew
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|smbus_readb_t
name|ichsmb_readb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|smbus_readw_t
name|ichsmb_readw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|smbus_pcall_t
name|ichsmb_pcall
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|smbus_bwrite_t
name|ichsmb_bwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|smbus_bread_t
name|ichsmb_bread
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Other functions */
end_comment

begin_function_decl
specifier|extern
name|void
name|ichsmb_device_intr
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ichsmb_release_resources
parameter_list|(
name|sc_p
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ichsmb_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ichsmb_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ICHSMB_ICHSMB_VAR_H */
end_comment

end_unit

