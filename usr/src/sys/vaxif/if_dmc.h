begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	if_dmc.h	6.1	83/07/29	*/
end_comment

begin_comment
comment|/*  * DMC-11 Interface  */
end_comment

begin_struct
struct|struct
name|dmcdevice
block|{
union|union
block|{
name|char
name|b
index|[
literal|8
index|]
decl_stmt|;
name|short
name|w
index|[
literal|4
index|]
decl_stmt|;
block|}
name|un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|bsel0
value|un.b[0]
end_define

begin_define
define|#
directive|define
name|bsel1
value|un.b[1]
end_define

begin_define
define|#
directive|define
name|bsel2
value|un.b[2]
end_define

begin_define
define|#
directive|define
name|bsel3
value|un.b[3]
end_define

begin_define
define|#
directive|define
name|bsel4
value|un.b[4]
end_define

begin_define
define|#
directive|define
name|bsel5
value|un.b[5]
end_define

begin_define
define|#
directive|define
name|bsel6
value|un.b[6]
end_define

begin_define
define|#
directive|define
name|bsel7
value|un.b[7]
end_define

begin_define
define|#
directive|define
name|sel0
value|un.w[0]
end_define

begin_define
define|#
directive|define
name|sel2
value|un.w[1]
end_define

begin_define
define|#
directive|define
name|sel4
value|un.w[2]
end_define

begin_define
define|#
directive|define
name|sel6
value|un.w[3]
end_define

begin_define
define|#
directive|define
name|DMCMTU
value|(2048)
end_define

begin_define
define|#
directive|define
name|RDYSCAN
value|16
end_define

begin_comment
comment|/* loop delay for RDYI after RQI */
end_comment

begin_comment
comment|/* defines for bsel0 */
end_comment

begin_define
define|#
directive|define
name|DMC_BACCI
value|0
end_define

begin_define
define|#
directive|define
name|DMC_CNTLI
value|1
end_define

begin_define
define|#
directive|define
name|DMC_PERR
value|2
end_define

begin_define
define|#
directive|define
name|DMC_BASEI
value|3
end_define

begin_define
define|#
directive|define
name|DMC_WRITE
value|0
end_define

begin_comment
comment|/* transmit block */
end_comment

begin_define
define|#
directive|define
name|DMC_READ
value|4
end_define

begin_comment
comment|/* read block */
end_comment

begin_define
define|#
directive|define
name|DMC_RQI
value|0040
end_define

begin_comment
comment|/* port request bit */
end_comment

begin_define
define|#
directive|define
name|DMC_IEI
value|0100
end_define

begin_comment
comment|/* enable input interrupts */
end_comment

begin_define
define|#
directive|define
name|DMC_RDYI
value|0200
end_define

begin_comment
comment|/* port ready */
end_comment

begin_comment
comment|/* defines for bsel1 */
end_comment

begin_define
define|#
directive|define
name|DMC_MCLR
value|0100
end_define

begin_comment
comment|/* DMC11 Master Clear */
end_comment

begin_define
define|#
directive|define
name|DMC_RUN
value|0200
end_define

begin_comment
comment|/* clock running */
end_comment

begin_comment
comment|/* defines for bsel2 */
end_comment

begin_define
define|#
directive|define
name|DMC_BACCO
value|0
end_define

begin_define
define|#
directive|define
name|DMC_CNTLO
value|1
end_define

begin_define
define|#
directive|define
name|DMC_OUX
value|0
end_define

begin_comment
comment|/* transmit block */
end_comment

begin_define
define|#
directive|define
name|DMC_OUR
value|4
end_define

begin_comment
comment|/* read block */
end_comment

begin_define
define|#
directive|define
name|DMC_IEO
value|0100
end_define

begin_comment
comment|/* enable output interrupts */
end_comment

begin_define
define|#
directive|define
name|DMC_RDYO
value|0200
end_define

begin_comment
comment|/* port available */
end_comment

begin_comment
comment|/* defines for CNTLI mode */
end_comment

begin_define
define|#
directive|define
name|DMC_HDPLX
value|02000
end_define

begin_comment
comment|/* half duplex DDCMP operation */
end_comment

begin_define
define|#
directive|define
name|DMC_SEC
value|04000
end_define

begin_comment
comment|/* half duplex secondary station */
end_comment

begin_define
define|#
directive|define
name|DMC_MAINT
value|00400
end_define

begin_comment
comment|/* enter maintenance mode */
end_comment

begin_comment
comment|/* defines for BACCI/O and BASEI mode */
end_comment

begin_define
define|#
directive|define
name|DMC_XMEM
value|0140000
end_define

begin_comment
comment|/* xmem bit position */
end_comment

begin_define
define|#
directive|define
name|DMC_CCOUNT
value|0037777
end_define

begin_comment
comment|/* character count mask */
end_comment

begin_define
define|#
directive|define
name|DMC_RESUME
value|0002000
end_define

begin_comment
comment|/* resume (BASEI only) */
end_comment

begin_comment
comment|/* defines for CNTLO */
end_comment

begin_define
define|#
directive|define
name|DMC_CNTMASK
value|01777
end_define

begin_define
define|#
directive|define
name|DMC_FATAL
value|01620
end_define

end_unit

