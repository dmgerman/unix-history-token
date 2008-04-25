begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License, Version 1.0 only  * (the "License").  You may not use this file except in compliance  * with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2003 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<ctf_impl.h>
end_include

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|_ctf_errlist
index|[]
init|=
block|{
literal|"File is not in CTF or ELF format"
block|,
comment|/* ECTF_FMT */
literal|"File uses more recent ELF version than libctf"
block|,
comment|/* ECTF_ELFVERS */
literal|"File uses more recent CTF version than libctf"
block|,
comment|/* ECTF_CTFVERS */
literal|"File is a different endian-ness than libctf"
block|,
comment|/* ECTF_ENDIAN */
literal|"Symbol table uses invalid entry size"
block|,
comment|/* ECTF_SYMTAB */
literal|"Symbol table data buffer is not valid"
block|,
comment|/* ECTF_SYMBAD */
literal|"String table data buffer is not valid"
block|,
comment|/* ECTF_STRBAD */
literal|"File data structure corruption detected"
block|,
comment|/* ECTF_CORRUPT */
literal|"File does not contain CTF data"
block|,
comment|/* ECTF_NOCTFDATA */
literal|"Buffer does not contain CTF data"
block|,
comment|/* ECTF_NOCTFBUF */
literal|"Symbol table information is not available"
block|,
comment|/* ECTF_NOSYMTAB */
literal|"Type information is in parent and unavailable"
block|,
comment|/* ECTF_NOPARENT */
literal|"Cannot import types with different data model"
block|,
comment|/* ECTF_DMODEL */
literal|"Failed to mmap a needed data section"
block|,
comment|/* ECTF_MMAP */
literal|"Decompression package SUNWzlib not installed"
block|,
comment|/* ECTF_ZMISSING */
literal|"Failed to initialize decompression library"
block|,
comment|/* ECTF_ZINIT */
literal|"Failed to allocate decompression buffer"
block|,
comment|/* ECTF_ZALLOC */
literal|"Failed to decompress CTF data"
block|,
comment|/* ECTF_DECOMPRESS */
literal|"External string table is not available"
block|,
comment|/* ECTF_STRTAB */
literal|"String name offset is corrupt"
block|,
comment|/* ECTF_BADNAME */
literal|"Invalid type identifier"
block|,
comment|/* ECTF_BADID */
literal|"Type is not a struct or union"
block|,
comment|/* ECTF_NOTSOU */
literal|"Type is not an enum"
block|,
comment|/* ECTF_NOTENUM */
literal|"Type is not a struct, union, or enum"
block|,
comment|/* ECTF_NOTSUE */
literal|"Type is not an integer or float"
block|,
comment|/* ECTF_NOTINTFP */
literal|"Type is not an array"
block|,
comment|/* ECTF_NOTARRAY */
literal|"Type does not reference another type"
block|,
comment|/* ECTF_NOTREF */
literal|"Input buffer is too small for type name"
block|,
comment|/* ECTF_NAMELEN */
literal|"No type information available for that name"
block|,
comment|/* ECTF_NOTYPE */
literal|"Syntax error in type name"
block|,
comment|/* ECTF_SYNTAX */
literal|"Symbol table entry is not a function"
block|,
comment|/* ECTF_NOTFUNC */
literal|"No function information available for symbol"
block|,
comment|/* ECTF_NOFUNCDAT */
literal|"Symbol table entry is not a data object"
block|,
comment|/* ECTF_NOTDATA */
literal|"No type information available for symbol"
block|,
comment|/* ECTF_NOTYPEDAT */
literal|"No label information available for that name"
block|,
comment|/* ECTF_NOLABEL */
literal|"File does not contain any labels"
block|,
comment|/* ECTF_NOLABELDATA */
literal|"Feature not supported"
block|,
comment|/* ECTF_NOTSUP */
literal|"Invalid enum element name"
block|,
comment|/* ECTF_NOENUMNAM */
literal|"Invalid member name"
block|,
comment|/* ECTF_NOMEMBNAM */
literal|"CTF container is read-only"
block|,
comment|/* ECTF_RDONLY */
literal|"Limit on number of dynamic type members reached"
block|,
comment|/* ECTF_DTFULL */
literal|"Limit on number of dynamic types reached"
block|,
comment|/* ECTF_FULL */
literal|"Duplicate member name definition"
block|,
comment|/* ECTF_DUPMEMBER */
literal|"Conflicting type is already defined"
block|,
comment|/* ECTF_CONFLICT */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|int
name|_ctf_nerr
init|=
sizeof|sizeof
argument_list|(
name|_ctf_errlist
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|_ctf_errlist
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|const
name|char
modifier|*
name|ctf_errmsg
parameter_list|(
name|int
name|error
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
if|if
condition|(
name|error
operator|>=
name|ECTF_BASE
operator|&&
operator|(
name|error
operator|-
name|ECTF_BASE
operator|)
operator|<
name|_ctf_nerr
condition|)
name|str
operator|=
name|_ctf_errlist
index|[
name|error
operator|-
name|ECTF_BASE
index|]
expr_stmt|;
else|else
name|str
operator|=
name|ctf_strerror
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
operator|(
name|str
condition|?
name|str
else|:
literal|"Unknown error"
operator|)
return|;
block|}
end_function

begin_function
name|int
name|ctf_errno
parameter_list|(
name|ctf_file_t
modifier|*
name|fp
parameter_list|)
block|{
return|return
operator|(
name|fp
operator|->
name|ctf_errno
operator|)
return|;
block|}
end_function

end_unit

