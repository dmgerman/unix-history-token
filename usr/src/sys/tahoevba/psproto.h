begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)psproto.h	7.1 (Berkeley) 5/21/88  */
end_comment

begin_comment
comment|/*  * PS300-Host Handshake Protocol Definitions.  */
end_comment

begin_comment
comment|/*  * Commands sent from host->PS300.  *  * In the initial handshake carried out when requesting  * one of these commands be performed, the PS300 always  * returns the identical code to indicate success.  */
end_comment

begin_define
define|#
directive|define
name|PS_ABORT
value|0x1000
end_define

begin_comment
comment|/* abort current command */
end_comment

begin_define
define|#
directive|define
name|PS_RESET
value|0x3000
end_define

begin_comment
comment|/* reset device */
end_comment

begin_define
define|#
directive|define
name|PS_RDNET
value|0x5000
end_define

begin_comment
comment|/* logical read */
end_comment

begin_define
define|#
directive|define
name|PS_LOOKUP
value|0x8000
end_define

begin_comment
comment|/* name lookup */
end_comment

begin_define
define|#
directive|define
name|PS_RDPHY
value|0x9000
end_define

begin_comment
comment|/* physical read */
end_comment

begin_define
define|#
directive|define
name|PS_WRPHY_SYNC
value|0xa000
end_define

begin_comment
comment|/* physical write w/ sync */
end_comment

begin_define
define|#
directive|define
name|PS_WRPHY
value|0xb000
end_define

begin_comment
comment|/* physical write */
end_comment

begin_define
define|#
directive|define
name|PS_WRNET
value|0xc000
end_define

begin_comment
comment|/* logical write */
end_comment

begin_define
define|#
directive|define
name|PS_DETACH
value|0xd000
end_define

begin_comment
comment|/* normal/diagnostic detach */
end_comment

begin_define
define|#
directive|define
name|PS_ATTACH
value|0xe000
end_define

begin_comment
comment|/* normal attach */
end_comment

begin_define
define|#
directive|define
name|PS_DATTACH
value|0xf000
end_define

begin_comment
comment|/* diagnostic attach */
end_comment

begin_define
define|#
directive|define
name|PS_DIOREAD
value|0x4000
end_define

begin_comment
comment|/* internal, wait for dioread attention */
end_comment

begin_comment
comment|/*  * Command responses from PS300->host.  */
end_comment

begin_define
define|#
directive|define
name|PS_DMAOK
parameter_list|(
name|code
parameter_list|)
value|((code)|0x0a00)
end_define

begin_comment
comment|/* successful dma transfer */
end_comment

begin_define
define|#
directive|define
name|PS_ADROK
parameter_list|(
name|code
parameter_list|)
value|((code)|0x0100)
end_define

begin_comment
comment|/* successful address tranfer */
end_comment

begin_define
define|#
directive|define
name|PS_CODE
parameter_list|(
name|v
parameter_list|)
value|((v)&0xf000)
end_define

begin_comment
comment|/* extract code from PS300 msg */
end_comment

begin_define
define|#
directive|define
name|PS_LUNIT
parameter_list|(
name|v
parameter_list|)
value|((v)&0x000f)
end_define

begin_comment
comment|/* extract PS300 unit from msg */
end_comment

begin_comment
comment|/*  * Single unit PS300 address list.  */
end_comment

begin_struct
struct|struct
name|psalist
block|{
name|u_short
name|nblocks
decl_stmt|;
comment|/* # of i/o vectors (we always use 1) */
name|u_short
name|addr
index|[
literal|2
index|]
decl_stmt|;
comment|/* PS300 address */
name|u_short
name|wc
decl_stmt|;
comment|/* transfer size */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The max dma size is actually 64KB, but  * we limit it to be just large enough for  * the maximum vector list as this is sufficient  * for our needs and we must allocate real  * memory to the intermediate buffer.  */
end_comment

begin_define
define|#
directive|define
name|PS_MAXDMA
value|(1024+2048*12)
end_define

begin_comment
comment|/*  * Pseudo commands used internally by the driver.  */
end_comment

begin_define
define|#
directive|define
name|PS_DMAOUT
value|0x0100
end_define

begin_comment
comment|/* dma buffer host->PS300 */
end_comment

begin_define
define|#
directive|define
name|PS_DMAIN
value|0x0200
end_define

begin_comment
comment|/* dma buffer PS300->host */
end_comment

begin_comment
comment|/*  * Default timeouts.  */
end_comment

begin_define
define|#
directive|define
name|PS_TIMEOUT
value|30
end_define

begin_comment
comment|/* dma/attention timeout (in hz) */
end_comment

begin_define
define|#
directive|define
name|PS_DIOTIMO
value|1000
end_define

begin_comment
comment|/* dio polling timeout */
end_comment

end_unit

