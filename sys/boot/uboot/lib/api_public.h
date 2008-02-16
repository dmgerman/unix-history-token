begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_API_PUBLIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_API_PUBLIC_H_
end_define

begin_define
define|#
directive|define
name|API_EINVAL
value|1
end_define

begin_comment
comment|/* invalid argument(s)	*/
end_comment

begin_define
define|#
directive|define
name|API_ENODEV
value|2
end_define

begin_comment
comment|/* no device		*/
end_comment

begin_define
define|#
directive|define
name|API_ENOMEM
value|3
end_define

begin_comment
comment|/* no memory		*/
end_comment

begin_define
define|#
directive|define
name|API_EBUSY
value|4
end_define

begin_comment
comment|/* busy, occupied etc.	*/
end_comment

begin_define
define|#
directive|define
name|API_EIO
value|5
end_define

begin_comment
comment|/* I/O error		*/
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|scp_t
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|API_SIG_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|API_SIG_MAGIC
value|"UBootAPI"
end_define

begin_define
define|#
directive|define
name|API_SIG_MAGLEN
value|8
end_define

begin_struct
struct|struct
name|api_signature
block|{
name|char
name|magic
index|[
name|API_SIG_MAGLEN
index|]
decl_stmt|;
comment|/* magic string */
name|uint16_t
name|version
decl_stmt|;
comment|/* API version */
name|uint32_t
name|checksum
decl_stmt|;
comment|/* checksum of this sig struct */
name|scp_t
name|syscall
decl_stmt|;
comment|/* entry point to the API */
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|API_RSVD
init|=
literal|0
block|,
name|API_GETC
block|,
name|API_PUTC
block|,
name|API_TSTC
block|,
name|API_PUTS
block|,
name|API_RESET
block|,
name|API_GET_SYS_INFO
block|,
name|API_UDELAY
block|,
name|API_GET_TIMER
block|,
name|API_DEV_ENUM
block|,
name|API_DEV_OPEN
block|,
name|API_DEV_CLOSE
block|,
name|API_DEV_READ
block|,
name|API_DEV_WRITE
block|,
name|API_ENV_ENUM
block|,
name|API_ENV_GET
block|,
name|API_ENV_SET
block|,
name|API_MAXCALL
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|MR_ATTR_FLASH
value|0x0001
end_define

begin_define
define|#
directive|define
name|MR_ATTR_DRAM
value|0x0002
end_define

begin_define
define|#
directive|define
name|MR_ATTR_SRAM
value|0x0003
end_define

begin_struct
struct|struct
name|mem_region
block|{
name|unsigned
name|long
name|start
decl_stmt|;
name|unsigned
name|long
name|size
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sys_info
block|{
name|unsigned
name|long
name|clk_bus
decl_stmt|;
name|unsigned
name|long
name|clk_cpu
decl_stmt|;
name|unsigned
name|long
name|bar
decl_stmt|;
name|struct
name|mem_region
modifier|*
name|mr
decl_stmt|;
name|int
name|mr_no
decl_stmt|;
comment|/* number of memory regions */
block|}
struct|;
end_struct

begin_undef
undef|#
directive|undef
name|CFG_64BIT_LBA
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|CFG_64BIT_LBA
end_ifdef

begin_typedef
typedef|typedef
name|u_int64_t
name|lbasize_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|long
name|lbasize_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|long
name|lbastart_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DEV_TYP_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|DEV_TYP_NET
value|0x0001
end_define

begin_define
define|#
directive|define
name|DEV_TYP_STOR
value|0x0002
end_define

begin_define
define|#
directive|define
name|DT_STOR_IDE
value|0x0010
end_define

begin_define
define|#
directive|define
name|DT_STOR_SCSI
value|0x0020
end_define

begin_define
define|#
directive|define
name|DT_STOR_USB
value|0x0040
end_define

begin_define
define|#
directive|define
name|DT_STOR_MMC
value|0x0080
end_define

begin_define
define|#
directive|define
name|DEV_STA_CLOSED
value|0x0000
end_define

begin_comment
comment|/* invalid, closed */
end_comment

begin_define
define|#
directive|define
name|DEV_STA_OPEN
value|0x0001
end_define

begin_comment
comment|/* open i.e. active */
end_comment

begin_struct
struct|struct
name|device_info
block|{
name|int
name|type
decl_stmt|;
name|void
modifier|*
name|cookie
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|lbasize_t
name|block_count
decl_stmt|;
comment|/* no of blocks */
name|unsigned
name|long
name|block_size
decl_stmt|;
comment|/* size of one block */
block|}
name|storage
struct|;
struct|struct
block|{
name|unsigned
name|char
name|hwaddr
index|[
literal|6
index|]
decl_stmt|;
block|}
name|net
struct|;
block|}
name|info
union|;
define|#
directive|define
name|di_stor
value|info.storage
define|#
directive|define
name|di_net
value|info.net
name|int
name|state
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _API_PUBLIC_H_ */
end_comment

end_unit

