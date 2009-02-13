begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * acm.h: Xen access control module interface defintions  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Reiner Sailer<sailer@watson.ibm.com>  * Copyright (c) 2005, International Business Machines Corporation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XEN_PUBLIC_ACM_H
end_ifndef

begin_define
define|#
directive|define
name|_XEN_PUBLIC_ACM_H
end_define

begin_include
include|#
directive|include
file|"xen.h"
end_include

begin_comment
comment|/* if ACM_DEBUG defined, all hooks should  * print a short trace message (comment it out  * when not in testing mode )  */
end_comment

begin_comment
comment|/* #define ACM_DEBUG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACM_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|printkd
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|printk(fmt,## args)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|printkd
parameter_list|(
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* default ssid reference value if not supplied */
end_comment

begin_define
define|#
directive|define
name|ACM_DEFAULT_SSID
value|0x0
end_define

begin_define
define|#
directive|define
name|ACM_DEFAULT_LOCAL_SSID
value|0x0
end_define

begin_comment
comment|/* Internal ACM ERROR types */
end_comment

begin_define
define|#
directive|define
name|ACM_OK
value|0
end_define

begin_define
define|#
directive|define
name|ACM_UNDEF
value|-1
end_define

begin_define
define|#
directive|define
name|ACM_INIT_SSID_ERROR
value|-2
end_define

begin_define
define|#
directive|define
name|ACM_INIT_SOID_ERROR
value|-3
end_define

begin_define
define|#
directive|define
name|ACM_ERROR
value|-4
end_define

begin_comment
comment|/* External ACCESS DECISIONS */
end_comment

begin_define
define|#
directive|define
name|ACM_ACCESS_PERMITTED
value|0
end_define

begin_define
define|#
directive|define
name|ACM_ACCESS_DENIED
value|-111
end_define

begin_define
define|#
directive|define
name|ACM_NULL_POINTER_ERROR
value|-200
end_define

begin_comment
comment|/*    Error codes reported in when trying to test for a new policy    These error codes are reported in an array of tuples where    each error code is followed by a parameter describing the error    more closely, such as a domain id. */
end_comment

begin_define
define|#
directive|define
name|ACM_EVTCHN_SHARING_VIOLATION
value|0x100
end_define

begin_define
define|#
directive|define
name|ACM_GNTTAB_SHARING_VIOLATION
value|0x101
end_define

begin_define
define|#
directive|define
name|ACM_DOMAIN_LOOKUP
value|0x102
end_define

begin_define
define|#
directive|define
name|ACM_CHWALL_CONFLICT
value|0x103
end_define

begin_define
define|#
directive|define
name|ACM_SSIDREF_IN_USE
value|0x104
end_define

begin_comment
comment|/* primary policy in lower 4 bits */
end_comment

begin_define
define|#
directive|define
name|ACM_NULL_POLICY
value|0
end_define

begin_define
define|#
directive|define
name|ACM_CHINESE_WALL_POLICY
value|1
end_define

begin_define
define|#
directive|define
name|ACM_SIMPLE_TYPE_ENFORCEMENT_POLICY
value|2
end_define

begin_define
define|#
directive|define
name|ACM_POLICY_UNDEFINED
value|15
end_define

begin_comment
comment|/* combinations have secondary policy component in higher 4bit */
end_comment

begin_define
define|#
directive|define
name|ACM_CHINESE_WALL_AND_SIMPLE_TYPE_ENFORCEMENT_POLICY
define|\
value|((ACM_SIMPLE_TYPE_ENFORCEMENT_POLICY<< 4) | ACM_CHINESE_WALL_POLICY)
end_define

begin_comment
comment|/* policy: */
end_comment

begin_define
define|#
directive|define
name|ACM_POLICY_NAME
parameter_list|(
name|X
parameter_list|)
define|\
value|((X) == (ACM_NULL_POLICY)) ? "NULL" :                        \     ((X) == (ACM_CHINESE_WALL_POLICY)) ? "CHINESE WALL" :        \     ((X) == (ACM_SIMPLE_TYPE_ENFORCEMENT_POLICY)) ? "SIMPLE TYPE ENFORCEMENT" : \     ((X) == (ACM_CHINESE_WALL_AND_SIMPLE_TYPE_ENFORCEMENT_POLICY)) ? "CHINESE WALL AND SIMPLE TYPE ENFORCEMENT" : \      "UNDEFINED"
end_define

begin_comment
comment|/* the following policy versions must be increased  * whenever the interpretation of the related  * policy's data structure changes  */
end_comment

begin_define
define|#
directive|define
name|ACM_POLICY_VERSION
value|3
end_define

begin_define
define|#
directive|define
name|ACM_CHWALL_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|ACM_STE_VERSION
value|1
end_define

begin_comment
comment|/* defines a ssid reference used by xen */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|ssidref_t
typedef|;
end_typedef

begin_comment
comment|/* hooks that are known to domains */
end_comment

begin_define
define|#
directive|define
name|ACMHOOK_none
value|0
end_define

begin_define
define|#
directive|define
name|ACMHOOK_sharing
value|1
end_define

begin_comment
comment|/* -------security policy relevant type definitions-------- */
end_comment

begin_comment
comment|/* type identifier; compares to "equal" or "not equal" */
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|domaintype_t
typedef|;
end_typedef

begin_comment
comment|/* CHINESE WALL POLICY DATA STRUCTURES  *  * current accumulated conflict type set:  * When a domain is started and has a type that is in  * a conflict set, the conflicting types are incremented in  * the aggregate set. When a domain is destroyed, the   * conflicting types to its type are decremented.  * If a domain has multiple types, this procedure works over  * all those types.  *  * conflict_aggregate_set[i] holds the number of  *   running domains that have a conflict with type i.  *  * running_types[i] holds the number of running domains  *        that include type i in their ssidref-referenced type set  *  * conflict_sets[i][j] is "0" if type j has no conflict  *    with type i and is "1" otherwise.  */
end_comment

begin_comment
comment|/* high-16 = version, low-16 = check magic */
end_comment

begin_define
define|#
directive|define
name|ACM_MAGIC
value|0x0001debc
end_define

begin_comment
comment|/* each offset in bytes from start of the struct they  * are part of */
end_comment

begin_comment
comment|/* V3 of the policy buffer aded a version structure */
end_comment

begin_struct
struct|struct
name|acm_policy_version
block|{
name|uint32_t
name|major
decl_stmt|;
name|uint32_t
name|minor
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* each buffer consists of all policy information for  * the respective policy given in the policy code  *  * acm_policy_buffer, acm_chwall_policy_buffer,  * and acm_ste_policy_buffer need to stay 32-bit aligned  * because we create binary policies also with external  * tools that assume packed representations (e.g. the java tool)  */
end_comment

begin_struct
struct|struct
name|acm_policy_buffer
block|{
name|uint32_t
name|policy_version
decl_stmt|;
comment|/* ACM_POLICY_VERSION */
name|uint32_t
name|magic
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|policy_reference_offset
decl_stmt|;
name|uint32_t
name|primary_policy_code
decl_stmt|;
name|uint32_t
name|primary_buffer_offset
decl_stmt|;
name|uint32_t
name|secondary_policy_code
decl_stmt|;
name|uint32_t
name|secondary_buffer_offset
decl_stmt|;
name|struct
name|acm_policy_version
name|xml_pol_version
decl_stmt|;
comment|/* add in V3 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|acm_policy_reference_buffer
block|{
name|uint32_t
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|acm_chwall_policy_buffer
block|{
name|uint32_t
name|policy_version
decl_stmt|;
comment|/* ACM_CHWALL_VERSION */
name|uint32_t
name|policy_code
decl_stmt|;
name|uint32_t
name|chwall_max_types
decl_stmt|;
name|uint32_t
name|chwall_max_ssidrefs
decl_stmt|;
name|uint32_t
name|chwall_max_conflictsets
decl_stmt|;
name|uint32_t
name|chwall_ssid_offset
decl_stmt|;
name|uint32_t
name|chwall_conflict_sets_offset
decl_stmt|;
name|uint32_t
name|chwall_running_types_offset
decl_stmt|;
name|uint32_t
name|chwall_conflict_aggregate_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|acm_ste_policy_buffer
block|{
name|uint32_t
name|policy_version
decl_stmt|;
comment|/* ACM_STE_VERSION */
name|uint32_t
name|policy_code
decl_stmt|;
name|uint32_t
name|ste_max_types
decl_stmt|;
name|uint32_t
name|ste_max_ssidrefs
decl_stmt|;
name|uint32_t
name|ste_ssid_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|acm_stats_buffer
block|{
name|uint32_t
name|magic
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|primary_policy_code
decl_stmt|;
name|uint32_t
name|primary_stats_offset
decl_stmt|;
name|uint32_t
name|secondary_policy_code
decl_stmt|;
name|uint32_t
name|secondary_stats_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|acm_ste_stats_buffer
block|{
name|uint32_t
name|ec_eval_count
decl_stmt|;
name|uint32_t
name|gt_eval_count
decl_stmt|;
name|uint32_t
name|ec_denied_count
decl_stmt|;
name|uint32_t
name|gt_denied_count
decl_stmt|;
name|uint32_t
name|ec_cachehit_count
decl_stmt|;
name|uint32_t
name|gt_cachehit_count
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|acm_ssid_buffer
block|{
name|uint32_t
name|len
decl_stmt|;
name|ssidref_t
name|ssidref
decl_stmt|;
name|uint32_t
name|policy_reference_offset
decl_stmt|;
name|uint32_t
name|primary_policy_code
decl_stmt|;
name|uint32_t
name|primary_max_types
decl_stmt|;
name|uint32_t
name|primary_types_offset
decl_stmt|;
name|uint32_t
name|secondary_policy_code
decl_stmt|;
name|uint32_t
name|secondary_max_types
decl_stmt|;
name|uint32_t
name|secondary_types_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

