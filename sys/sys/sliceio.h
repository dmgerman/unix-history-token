begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SLICEIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SLICEIO_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|SLCTYPE_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|SLCNAME_SIZE
value|32
end_define

begin_struct
struct|struct
name|sliceinfo
block|{
name|u_int64_t
name|size
decl_stmt|;
name|u_int32_t
name|blocksize
decl_stmt|;
name|char
name|type
index|[
name|SLCTYPE_SIZE
index|]
decl_stmt|;
comment|/* e.g. sd or raw*/
name|char
name|hint
index|[
name|SLCTYPE_SIZE
index|]
decl_stmt|;
comment|/* e.g. mbr or ""*/
name|char
name|handler
index|[
name|SLCTYPE_SIZE
index|]
decl_stmt|;
comment|/* e.g. mbr or "" */
name|char
name|devicename
index|[
name|SLCNAME_SIZE
index|]
decl_stmt|;
comment|/* e.g. sd0s1a */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|subsliceinfo
block|{
name|struct
name|sliceinfo
name|wholesliceinfo
decl_stmt|;
comment|/* size of the whole slice */
name|int
name|slicenumber
decl_stmt|;
comment|/* which subslice we are on */
name|u_int64_t
name|offset
decl_stmt|;
comment|/* where that subslice starts */
name|struct
name|sliceinfo
name|subsliceinfo
decl_stmt|;
comment|/* info about that subslice */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SLCIOCRESET
value|_IO('S', 0)
end_define

begin_comment
comment|/* reset and reprobe. */
end_comment

begin_define
define|#
directive|define
name|SLCIOCINQ
value|_IOR('S', 2, struct sliceinfo)
end_define

begin_comment
comment|/* info on container */
end_comment

begin_define
define|#
directive|define
name|SLCIOCMOD
value|_IOW('S', 3, struct sliceinfo)
end_define

begin_comment
comment|/* force container */
end_comment

begin_define
define|#
directive|define
name|SLCIOCGETSUB
value|_IOWR('S', 4, struct subsliceinfo)
end_define

begin_comment
comment|/* get sub info */
end_comment

begin_define
define|#
directive|define
name|SLCIOCSETSUB
value|_IOWR('S', 5, struct subsliceinfo)
end_define

begin_comment
comment|/* set sub info */
end_comment

begin_define
define|#
directive|define
name|SLCIOCTRANSBAD
value|_IOWR('S', 6, daddr_t)
end_define

begin_comment
comment|/* map bad144 sector */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SLICEIO_H_ */
end_comment

end_unit

