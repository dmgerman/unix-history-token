begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_EROM_BHND_EROM_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_EROM_BHND_EROM_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kobj.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/bhnd.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/bhnd_erom_types.h>
end_include

begin_include
include|#
directive|include
file|"bhnd_erom_if.h"
end_include

begin_function_decl
name|bhnd_erom_t
modifier|*
name|bhnd_erom_alloc
parameter_list|(
name|bhnd_erom_class_t
modifier|*
name|cls
parameter_list|,
specifier|const
name|struct
name|bhnd_chipid
modifier|*
name|cid
parameter_list|,
name|device_t
name|parent
parameter_list|,
name|int
name|rid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_erom_init_static
parameter_list|(
name|bhnd_erom_class_t
modifier|*
name|cls
parameter_list|,
name|bhnd_erom_t
modifier|*
name|erom
parameter_list|,
name|size_t
name|esize
parameter_list|,
specifier|const
name|struct
name|bhnd_chipid
modifier|*
name|cid
parameter_list|,
name|bus_space_tag_t
name|bst
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_erom_fini_static
parameter_list|(
name|bhnd_erom_t
modifier|*
name|erom
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_erom_free
parameter_list|(
name|bhnd_erom_t
modifier|*
name|erom
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Abstract bhnd_erom instance state. Must be first member of all subclass  * instances.  */
end_comment

begin_struct
struct|struct
name|bhnd_erom
block|{
name|KOBJ_FIELDS
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** Number of additional bytes to reserve for statically allocated  *  bhnd_erom instances. */
end_comment

begin_define
define|#
directive|define
name|BHND_EROM_STATIC_BYTES
value|64
end_define

begin_comment
comment|/**  * A bhnd_erom instance structure large enough to statically allocate  * any known bhnd_erom subclass.  *   * The maximum size of subclasses is verified statically in  * BHND_EROM_DEFINE_CLASS(), and at runtime in bhnd_erom_init_static().  */
end_comment

begin_struct
struct|struct
name|bhnd_erom_static
block|{
name|struct
name|bhnd_erom
name|obj
decl_stmt|;
name|uint8_t
name|idata
index|[
name|BHND_EROM_STATIC_BYTES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** Registered EROM parser class instances. */
end_comment

begin_expr_stmt
name|SET_DECLARE
argument_list|(
name|bhnd_erom_class_set
argument_list|,
name|bhnd_erom_class_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|BHND_EROM_DEFINE_CLASS
parameter_list|(
name|name
parameter_list|,
name|classvar
parameter_list|,
name|methods
parameter_list|,
name|size
parameter_list|)
define|\
value|DEFINE_CLASS_0(name, classvar, methods, size);		\ 	BHND_EROM_CLASS_DEF(classvar);				\ 	_Static_assert(size<= sizeof(struct bhnd_erom_static),	\ 	    "cannot statically allocate instance data; "	\ 	        "increase BHND_EROM_STATIC_BYTES");
end_define

begin_define
define|#
directive|define
name|BHND_EROM_CLASS_DEF
parameter_list|(
name|classvar
parameter_list|)
value|DATA_SET(bhnd_erom_class_set, classvar)
end_define

begin_comment
comment|/**  * Probe to see if this device enumeration class supports the bhnd bus  * mapped by the given resource, returning a standard newbus device probe  * result (see BUS_PROBE_*) and the probed chip identification.  *  * @param	cls	The erom class to probe.  * @param	res	A resource mapping the first bus core (EXTIF or  *			ChipCommon)  * @param	offset	Offset to the first bus core within @p res.  * @param	hint	Identification hint used to identify the device. If  *			chipset supports standard chip identification registers  *			within the first core, this parameter should be NULL.  * @param[out]	cid	On success, the probed chip identifier.  *  * @retval 0		if this is the only possible device enumeration  *			parser for the probed bus.  * @retval negative	if the probe succeeds, a negative value should be  *			returned; the parser returning the highest negative  *			value will be selected to handle device enumeration.  * @retval ENXIO	If the bhnd bus type is not handled by this parser.  * @retval positive	if an error occurs during probing, a regular unix error  *			code should be returned.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_erom_probe
parameter_list|(
name|bhnd_erom_class_t
modifier|*
name|cls
parameter_list|,
name|struct
name|bhnd_resource
modifier|*
name|res
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
specifier|const
name|struct
name|bhnd_chipid
modifier|*
name|hint
parameter_list|,
name|struct
name|bhnd_chipid
modifier|*
name|cid
parameter_list|)
block|{
return|return
operator|(
name|BHND_EROM_PROBE
argument_list|(
name|cls
argument_list|,
name|res
argument_list|,
name|offset
argument_list|,
name|hint
argument_list|,
name|cid
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Probe to see if this device enumeration class supports the bhnd bus  * mapped at the given bus space tag and handle, returning a standard  * newbus device probe result (see BUS_PROBE_*) and the probed  * chip identification.  *  * @param	cls	The erom class to probe.  * @param	bst	Bus space tag.  * @param	bsh	Bus space handle mapping the EXTIF or ChipCommon core.  * @param	paddr	The physical address of the core mapped by @p bst and  *			@p bsh.  * @param	hint	Identification hint used to identify the device. If  *			chipset supports standard chip identification registers  *			within the first core, this parameter should be NULL.  * @param[out]	cid	On success, the probed chip identifier.  *  * @retval 0		if this is the only possible device enumeration  *			parser for the probed bus.  * @retval negative	if the probe succeeds, a negative value should be  *			returned; the parser returning the lowest value will  *			be selected to handle device enumeration.  * @retval ENXIO	If the bhnd bus type is not handled by this parser.  * @retval positive	if an error occurs during probing, a regular unix error  *			code should be returned.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_erom_probe_static
parameter_list|(
name|bhnd_erom_class_t
modifier|*
name|cls
parameter_list|,
name|bus_space_tag_t
name|bst
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_addr_t
name|paddr
parameter_list|,
specifier|const
name|struct
name|bhnd_chipid
modifier|*
name|hint
parameter_list|,
name|struct
name|bhnd_chipid
modifier|*
name|cid
parameter_list|)
block|{
return|return
operator|(
name|BHND_EROM_PROBE_STATIC
argument_list|(
name|cls
argument_list|,
name|bst
argument_list|,
name|bsh
argument_list|,
name|paddr
argument_list|,
name|hint
argument_list|,
name|cid
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Parse all cores descriptors in @p erom, returning the array in @p cores and  * the count in @p num_cores.  *   * The memory allocated for the table must be freed via  * bhnd_erom_free_core_table().  *   * @param	erom		The erom parser to be queried.  * @param[out]	cores		The table of parsed core descriptors.  * @param[out]	num_cores	The number of core records in @p cores.  *   * @retval 0		success  * @retval non-zero	if an error occurs, a regular unix error code will  *			be returned.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_erom_get_core_table
parameter_list|(
name|bhnd_erom_t
modifier|*
name|erom
parameter_list|,
name|struct
name|bhnd_core_info
modifier|*
modifier|*
name|cores
parameter_list|,
name|u_int
modifier|*
name|num_cores
parameter_list|)
block|{
return|return
operator|(
name|BHND_EROM_GET_CORE_TABLE
argument_list|(
name|erom
argument_list|,
name|cores
argument_list|,
name|num_cores
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Free any memory allocated in a previous call to BHND_EROM_GET_CORE_TABLE().  *  * @param	erom		The erom parser instance.  * @param	cores		A core table allocated by @p erom.   */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|bhnd_erom_free_core_table
parameter_list|(
name|bhnd_erom_t
modifier|*
name|erom
parameter_list|,
name|struct
name|bhnd_core_info
modifier|*
name|cores
parameter_list|)
block|{
return|return
operator|(
name|BHND_EROM_FREE_CORE_TABLE
argument_list|(
name|erom
argument_list|,
name|cores
argument_list|)
operator|)
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * Locate the first core table entry in @p erom that matches @p desc.  *  * @param	erom	The erom parser to be queried.  * @param	desc	A core match descriptor.  * @param[out]	core	On success, the matching core info record.  *   * @retval 0		success  * @retval ENOENT	No core matching @p desc was found.  * @retval non-zero	Reading or parsing failed.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_erom_lookup_core
parameter_list|(
name|bhnd_erom_t
modifier|*
name|erom
parameter_list|,
specifier|const
name|struct
name|bhnd_core_match
modifier|*
name|desc
parameter_list|,
name|struct
name|bhnd_core_info
modifier|*
name|core
parameter_list|)
block|{
return|return
operator|(
name|BHND_EROM_LOOKUP_CORE
argument_list|(
name|erom
argument_list|,
name|desc
argument_list|,
name|core
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Locate the first core table entry in @p erom that matches @p desc,  * and return the specified port region's base address and size.  *  * If a core matching @p desc is not found, or the requested port region  * is not mapped to the matching core, ENOENT is returned.  *  * @param	erom	The erom parser to be queried.  * @param	desc	A core match descriptor.  * @param	type	The port type to search for.  * @param	port	The port to search for.  * @param	region	The port region to search for.  * @param[out]	core	If not NULL, will be populated with the matched core  *			info record on success.  * @param[out]	addr	On success, the base address of the port region.  * @param[out]	size	On success, the total size of the port region.  *   * @retval 0		success  * @retval ENOENT	No core matching @p desc was found.  * @retval ENOENT	No port region matching @p type, @p port, and @p region  *			was found.  * @retval non-zero	Reading or parsing failed.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_erom_lookup_core_addr
parameter_list|(
name|bhnd_erom_t
modifier|*
name|erom
parameter_list|,
specifier|const
name|struct
name|bhnd_core_match
modifier|*
name|desc
parameter_list|,
name|bhnd_port_type
name|type
parameter_list|,
name|u_int
name|port
parameter_list|,
name|u_int
name|region
parameter_list|,
name|struct
name|bhnd_core_info
modifier|*
name|core
parameter_list|,
name|bhnd_addr_t
modifier|*
name|addr
parameter_list|,
name|bhnd_size_t
modifier|*
name|size
parameter_list|)
block|{
return|return
operator|(
name|BHND_EROM_LOOKUP_CORE_ADDR
argument_list|(
name|erom
argument_list|,
name|desc
argument_list|,
name|type
argument_list|,
name|port
argument_list|,
name|region
argument_list|,
name|core
argument_list|,
name|addr
argument_list|,
name|size
argument_list|)
operator|)
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * Enumerate and print all entries in @p erom.  *   * @param	erom	The erom parser to be enumerated.  *   * @retval 0		success  * @retval non-zero	If an error occurs parsing the EROM table, a regular  *			unix error code will be returned.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_erom_dump
parameter_list|(
name|bhnd_erom_t
modifier|*
name|erom
parameter_list|)
block|{
return|return
operator|(
name|BHND_EROM_DUMP
argument_list|(
name|erom
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_EROM_BHND_EROM_H_ */
end_comment

end_unit

