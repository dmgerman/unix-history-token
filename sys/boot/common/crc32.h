begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *  COPYRIGHT (C) 1986 Gary S. Brown.  You may use this program, or  *  code or tables extracted from it, as desired without restriction.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CRC32_H_
end_ifndef

begin_define
define|#
directive|define
name|_CRC32_H_
end_define

begin_function_decl
name|uint32_t
name|crc32
parameter_list|(
specifier|const
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_CRC32_H_ */
end_comment

end_unit

