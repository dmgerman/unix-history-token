begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Definitions for Clearinghouse VERSION 2 NUMBER 2.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__Clearinghouse2
end_ifndef

begin_define
define|#
directive|define
name|__Clearinghouse2
end_define

begin_include
include|#
directive|include
file|<xnscourier/courier.h>
end_include

begin_include
include|#
directive|include
file|<xnscourier/courierconnection.h>
end_include

begin_comment
comment|/*  * Definitions from DEPENDS UPON BulkData inclusion  * (must be linked with BulkData1_support.c also)  */
end_comment

begin_include
include|#
directive|include
file|<xnscourier/BulkData1.h>
end_include

begin_comment
comment|/*  * Definitions from DEPENDS UPON Authentication inclusion  * (must be linked with Authentication1_support.c also)  */
end_comment

begin_include
include|#
directive|include
file|<xnscourier/Authentication1.h>
end_include

begin_typedef
typedef|typedef
name|String
name|Clearinghouse2_Organization
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_Organization
value|sizeof_String
end_define

begin_define
define|#
directive|define
name|clear_Clearinghouse2_Organization
value|clear_String
end_define

begin_define
define|#
directive|define
name|externalize_Clearinghouse2_Organization
value|externalize_String
end_define

begin_define
define|#
directive|define
name|internalize_Clearinghouse2_Organization
value|internalize_String
end_define

begin_typedef
typedef|typedef
name|String
name|Clearinghouse2_Domain
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_Domain
value|sizeof_String
end_define

begin_define
define|#
directive|define
name|clear_Clearinghouse2_Domain
value|clear_String
end_define

begin_define
define|#
directive|define
name|externalize_Clearinghouse2_Domain
value|externalize_String
end_define

begin_define
define|#
directive|define
name|internalize_Clearinghouse2_Domain
value|internalize_String
end_define

begin_typedef
typedef|typedef
name|String
name|Clearinghouse2_Object
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_Object
value|sizeof_String
end_define

begin_define
define|#
directive|define
name|clear_Clearinghouse2_Object
value|clear_String
end_define

begin_define
define|#
directive|define
name|externalize_Clearinghouse2_Object
value|externalize_String
end_define

begin_define
define|#
directive|define
name|internalize_Clearinghouse2_Object
value|internalize_String
end_define

begin_decl_stmt
specifier|static
name|Cardinal
name|Clearinghouse2_maxOrganizationsLength
init|=
block|{
literal|20
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|Cardinal
name|Clearinghouse2_maxDomainLength
init|=
block|{
literal|20
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|Cardinal
name|Clearinghouse2_maxObjectLength
init|=
block|{
literal|40
block|}
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|String
name|Clearinghouse2_OrganizationName
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_OrganizationName
value|sizeof_String
end_define

begin_define
define|#
directive|define
name|clear_Clearinghouse2_OrganizationName
value|clear_String
end_define

begin_define
define|#
directive|define
name|externalize_Clearinghouse2_OrganizationName
value|externalize_String
end_define

begin_define
define|#
directive|define
name|internalize_Clearinghouse2_OrganizationName
value|internalize_String
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|String
name|organization
decl_stmt|;
name|String
name|domain
decl_stmt|;
block|}
name|Clearinghouse2_TwoPartName
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Clearinghouse2_TwoPartName
name|Clearinghouse2_DomainName
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_DomainName
value|sizeof_Clearinghouse2_TwoPartName
end_define

begin_define
define|#
directive|define
name|clear_Clearinghouse2_DomainName
value|clear_Clearinghouse2_TwoPartName
end_define

begin_define
define|#
directive|define
name|externalize_Clearinghouse2_DomainName
value|externalize_Clearinghouse2_TwoPartName
end_define

begin_define
define|#
directive|define
name|internalize_Clearinghouse2_DomainName
value|internalize_Clearinghouse2_TwoPartName
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|String
name|organization
decl_stmt|;
name|String
name|domain
decl_stmt|;
name|String
name|object
decl_stmt|;
block|}
name|Clearinghouse2_ThreePartName
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Clearinghouse2_ThreePartName
name|Clearinghouse2_ObjectName
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_ObjectName
value|sizeof_Clearinghouse2_ThreePartName
end_define

begin_define
define|#
directive|define
name|clear_Clearinghouse2_ObjectName
value|clear_Clearinghouse2_ThreePartName
end_define

begin_define
define|#
directive|define
name|externalize_Clearinghouse2_ObjectName
value|externalize_Clearinghouse2_ThreePartName
end_define

begin_define
define|#
directive|define
name|internalize_Clearinghouse2_ObjectName
value|internalize_Clearinghouse2_ThreePartName
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_ThreePartName
name|Clearinghouse2_Name
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_Name
value|sizeof_Clearinghouse2_ThreePartName
end_define

begin_define
define|#
directive|define
name|clear_Clearinghouse2_Name
value|clear_Clearinghouse2_ThreePartName
end_define

begin_define
define|#
directive|define
name|externalize_Clearinghouse2_Name
value|externalize_Clearinghouse2_ThreePartName
end_define

begin_define
define|#
directive|define
name|internalize_Clearinghouse2_Name
value|internalize_Clearinghouse2_ThreePartName
end_define

begin_typedef
typedef|typedef
name|String
name|Clearinghouse2_OrganizationNamePattern
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_OrganizationNamePattern
value|sizeof_String
end_define

begin_define
define|#
directive|define
name|clear_Clearinghouse2_OrganizationNamePattern
value|clear_String
end_define

begin_define
define|#
directive|define
name|externalize_Clearinghouse2_OrganizationNamePattern
value|externalize_String
end_define

begin_define
define|#
directive|define
name|internalize_Clearinghouse2_OrganizationNamePattern
value|internalize_String
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_TwoPartName
name|Clearinghouse2_DomainNamePattern
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_DomainNamePattern
value|sizeof_Clearinghouse2_TwoPartName
end_define

begin_define
define|#
directive|define
name|clear_Clearinghouse2_DomainNamePattern
value|clear_Clearinghouse2_TwoPartName
end_define

begin_define
define|#
directive|define
name|externalize_Clearinghouse2_DomainNamePattern
value|externalize_Clearinghouse2_TwoPartName
end_define

begin_define
define|#
directive|define
name|internalize_Clearinghouse2_DomainNamePattern
value|internalize_Clearinghouse2_TwoPartName
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_ThreePartName
name|Clearinghouse2_ObjectNamePattern
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_ObjectNamePattern
value|sizeof_Clearinghouse2_ThreePartName
end_define

begin_define
define|#
directive|define
name|clear_Clearinghouse2_ObjectNamePattern
value|clear_Clearinghouse2_ThreePartName
end_define

begin_define
define|#
directive|define
name|externalize_Clearinghouse2_ObjectNamePattern
value|externalize_Clearinghouse2_ThreePartName
end_define

begin_define
define|#
directive|define
name|internalize_Clearinghouse2_ObjectNamePattern
value|internalize_Clearinghouse2_ThreePartName
end_define

begin_struct_decl
specifier|extern
struct_decl|struct
name|Clearinghouse2_StreamOfDomain
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|Clearinghouse2_StreamOfDomain
name|Clearinghouse2_StreamOfDomain
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Cardinal
name|length
decl_stmt|;
name|String
modifier|*
name|sequence
decl_stmt|;
block|}
name|Clearinghouse2_T_r2_9
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_T_r2_9
name|segment
decl_stmt|;
name|NilRecord
name|restOfStream
decl_stmt|;
block|}
name|Clearinghouse2_T_c2_8
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Cardinal
name|length
decl_stmt|;
name|String
modifier|*
name|sequence
decl_stmt|;
block|}
name|Clearinghouse2_T_c2_10
typedef|;
end_typedef

begin_struct
struct|struct
name|Clearinghouse2_StreamOfDomain
block|{
name|StreamEnumerator
name|designator
decl_stmt|;
union|union
block|{
name|Clearinghouse2_T_c2_8
name|u_nextSegment
decl_stmt|;
define|#
directive|define
name|nextSegment_case
value|u.u_nextSegment
name|Clearinghouse2_T_c2_10
name|u_lastSegment
decl_stmt|;
define|#
directive|define
name|lastSegment_case
value|u.u_lastSegment
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct_decl
specifier|extern
struct_decl|struct
name|Clearinghouse2_StreamOfDomainName
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|Clearinghouse2_StreamOfDomainName
name|Clearinghouse2_StreamOfDomainName
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Cardinal
name|length
decl_stmt|;
name|Clearinghouse2_TwoPartName
modifier|*
name|sequence
decl_stmt|;
block|}
name|Clearinghouse2_T_r2_12
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_T_r2_12
name|segment
decl_stmt|;
name|NilRecord
name|restOfStream
decl_stmt|;
block|}
name|Clearinghouse2_T_c2_11
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Cardinal
name|length
decl_stmt|;
name|Clearinghouse2_TwoPartName
modifier|*
name|sequence
decl_stmt|;
block|}
name|Clearinghouse2_T_c2_13
typedef|;
end_typedef

begin_struct
struct|struct
name|Clearinghouse2_StreamOfDomainName
block|{
name|StreamEnumerator
name|designator
decl_stmt|;
union|union
block|{
name|Clearinghouse2_T_c2_11
name|u_nextSegment
decl_stmt|;
define|#
directive|define
name|nextSegment_case
value|u.u_nextSegment
name|Clearinghouse2_T_c2_13
name|u_lastSegment
decl_stmt|;
define|#
directive|define
name|lastSegment_case
value|u.u_lastSegment
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct_decl
specifier|extern
struct_decl|struct
name|Clearinghouse2_StreamOfObject
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|Clearinghouse2_StreamOfObject
name|Clearinghouse2_StreamOfObject
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Cardinal
name|length
decl_stmt|;
name|String
modifier|*
name|sequence
decl_stmt|;
block|}
name|Clearinghouse2_T_r2_15
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_T_r2_15
name|segment
decl_stmt|;
name|NilRecord
name|restOfStream
decl_stmt|;
block|}
name|Clearinghouse2_T_c2_14
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Cardinal
name|length
decl_stmt|;
name|String
modifier|*
name|sequence
decl_stmt|;
block|}
name|Clearinghouse2_T_c2_16
typedef|;
end_typedef

begin_struct
struct|struct
name|Clearinghouse2_StreamOfObject
block|{
name|StreamEnumerator
name|designator
decl_stmt|;
union|union
block|{
name|Clearinghouse2_T_c2_14
name|u_nextSegment
decl_stmt|;
define|#
directive|define
name|nextSegment_case
value|u.u_nextSegment
name|Clearinghouse2_T_c2_16
name|u_lastSegment
decl_stmt|;
define|#
directive|define
name|lastSegment_case
value|u.u_lastSegment
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct_decl
specifier|extern
struct_decl|struct
name|Clearinghouse2_StreamOfObjectName
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|Clearinghouse2_StreamOfObjectName
name|Clearinghouse2_StreamOfObjectName
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Cardinal
name|length
decl_stmt|;
name|Clearinghouse2_ThreePartName
modifier|*
name|sequence
decl_stmt|;
block|}
name|Clearinghouse2_T_r2_18
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_T_r2_18
name|segment
decl_stmt|;
name|NilRecord
name|restOfStream
decl_stmt|;
block|}
name|Clearinghouse2_T_c2_17
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Cardinal
name|length
decl_stmt|;
name|Clearinghouse2_ThreePartName
modifier|*
name|sequence
decl_stmt|;
block|}
name|Clearinghouse2_T_c2_19
typedef|;
end_typedef

begin_struct
struct|struct
name|Clearinghouse2_StreamOfObjectName
block|{
name|StreamEnumerator
name|designator
decl_stmt|;
union|union
block|{
name|Clearinghouse2_T_c2_17
name|u_nextSegment
decl_stmt|;
define|#
directive|define
name|nextSegment_case
value|u.u_nextSegment
name|Clearinghouse2_T_c2_19
name|u_lastSegment
decl_stmt|;
define|#
directive|define
name|lastSegment_case
value|u.u_lastSegment
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct_decl
specifier|extern
struct_decl|struct
name|Clearinghouse2_StreamOfOrganization
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|Clearinghouse2_StreamOfOrganization
name|Clearinghouse2_StreamOfOrganization
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Cardinal
name|length
decl_stmt|;
name|String
modifier|*
name|sequence
decl_stmt|;
block|}
name|Clearinghouse2_T_r2_21
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_T_r2_21
name|segment
decl_stmt|;
name|NilRecord
name|restOfStream
decl_stmt|;
block|}
name|Clearinghouse2_T_c2_20
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Cardinal
name|length
decl_stmt|;
name|String
modifier|*
name|sequence
decl_stmt|;
block|}
name|Clearinghouse2_T_c2_22
typedef|;
end_typedef

begin_struct
struct|struct
name|Clearinghouse2_StreamOfOrganization
block|{
name|StreamEnumerator
name|designator
decl_stmt|;
union|union
block|{
name|Clearinghouse2_T_c2_20
name|u_nextSegment
decl_stmt|;
define|#
directive|define
name|nextSegment_case
value|u.u_nextSegment
name|Clearinghouse2_T_c2_22
name|u_lastSegment
decl_stmt|;
define|#
directive|define
name|lastSegment_case
value|u.u_lastSegment
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_struct_decl
specifier|extern
struct_decl|struct
name|Clearinghouse2_StreamOfThreePartName
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|Clearinghouse2_StreamOfThreePartName
name|Clearinghouse2_StreamOfThreePartName
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Cardinal
name|length
decl_stmt|;
name|Clearinghouse2_ThreePartName
modifier|*
name|sequence
decl_stmt|;
block|}
name|Clearinghouse2_T_r2_24
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_T_r2_24
name|segment
decl_stmt|;
name|NilRecord
name|restOfStream
decl_stmt|;
block|}
name|Clearinghouse2_T_c2_23
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Cardinal
name|length
decl_stmt|;
name|Clearinghouse2_ThreePartName
modifier|*
name|sequence
decl_stmt|;
block|}
name|Clearinghouse2_T_c2_25
typedef|;
end_typedef

begin_struct
struct|struct
name|Clearinghouse2_StreamOfThreePartName
block|{
name|StreamEnumerator
name|designator
decl_stmt|;
union|union
block|{
name|Clearinghouse2_T_c2_23
name|u_nextSegment
decl_stmt|;
define|#
directive|define
name|nextSegment_case
value|u.u_nextSegment
name|Clearinghouse2_T_c2_25
name|u_lastSegment
decl_stmt|;
define|#
directive|define
name|lastSegment_case
value|u.u_lastSegment
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|LongCardinal
name|Clearinghouse2_Property
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_Property
value|sizeof_LongCardinal
end_define

begin_define
define|#
directive|define
name|clear_Clearinghouse2_Property
value|clear_LongCardinal
end_define

begin_define
define|#
directive|define
name|externalize_Clearinghouse2_Property
value|externalize_LongCardinal
end_define

begin_define
define|#
directive|define
name|internalize_Clearinghouse2_Property
value|internalize_LongCardinal
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Cardinal
name|length
decl_stmt|;
name|LongCardinal
modifier|*
name|sequence
decl_stmt|;
block|}
name|Clearinghouse2_Properties
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_Properties
parameter_list|(
name|p
parameter_list|)
value|(1 + (p)->length * 2)
end_define

begin_decl_stmt
specifier|static
name|LongCardinal
name|Clearinghouse2_all
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|LongCardinal
name|Clearinghouse2_nullProperty
init|=
block|{
literal|037777777777
block|}
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
block|{
name|Cardinal
name|length
decl_stmt|;
name|Unspecified
modifier|*
name|sequence
decl_stmt|;
block|}
name|Clearinghouse2_Item
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_Item
parameter_list|(
name|p
parameter_list|)
value|(1 + (p)->length * 1)
end_define

begin_typedef
typedef|typedef
name|Unspecified
name|Clearinghouse2_T_r2_26
index|[
literal|2
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_T_r2_26
parameter_list|(
name|p
parameter_list|)
value|2
end_define

begin_define
define|#
directive|define
name|clear_Clearinghouse2_T_r2_26
parameter_list|(
name|p
parameter_list|)
end_define

begin_typedef
typedef|typedef
name|Unspecified
name|Clearinghouse2_T_r2_27
index|[
literal|3
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_T_r2_27
parameter_list|(
name|p
parameter_list|)
value|3
end_define

begin_define
define|#
directive|define
name|clear_Clearinghouse2_T_r2_27
parameter_list|(
name|p
parameter_list|)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_T_r2_26
name|network
decl_stmt|;
name|Clearinghouse2_T_r2_27
name|host
decl_stmt|;
name|Unspecified
name|socket
decl_stmt|;
block|}
name|Clearinghouse2_NetworkAddress
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_NetworkAddress
parameter_list|(
name|p
parameter_list|)
value|6
end_define

begin_define
define|#
directive|define
name|clear_Clearinghouse2_NetworkAddress
parameter_list|(
name|p
parameter_list|)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Cardinal
name|length
decl_stmt|;
name|Clearinghouse2_NetworkAddress
modifier|*
name|sequence
decl_stmt|;
block|}
name|Clearinghouse2_NetworkAddressList
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_NetworkAddressList
parameter_list|(
name|p
parameter_list|)
value|(1 + (p)->length * 6)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Authentication1_Credentials
name|credentials
decl_stmt|;
name|Authentication1_Verifier
name|verifier
decl_stmt|;
block|}
name|Clearinghouse2_Authenticator
typedef|;
end_typedef

begin_decl_stmt
specifier|static
name|String
name|Clearinghouse2_wildcard
init|=
block|{
literal|"*"
block|}
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
enum|enum
block|{
name|first
init|=
literal|1
block|,
name|second
init|=
literal|2
block|}
name|Clearinghouse2_WhichArgument
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_WhichArgument
value|sizeof_enumeration
end_define

begin_define
define|#
directive|define
name|clear_Clearinghouse2_WhichArgument
value|clear_enumeration
end_define

begin_define
define|#
directive|define
name|externalize_Clearinghouse2_WhichArgument
value|externalize_enumeration
end_define

begin_define
define|#
directive|define
name|internalize_Clearinghouse2_WhichArgument
value|internalize_enumeration
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|illegalProperty
init|=
literal|10
block|,
name|illegalOrganizationName
init|=
literal|11
block|,
name|illegalDomainName
init|=
literal|12
block|,
name|illegalObjectName
init|=
literal|13
block|,
name|noSuchOrganization
init|=
literal|14
block|,
name|noSuchDomain
init|=
literal|15
block|,
name|noSuchObject
init|=
literal|16
block|}
name|Clearinghouse2_ArgumentProblem
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_ArgumentProblem
value|sizeof_enumeration
end_define

begin_define
define|#
directive|define
name|clear_Clearinghouse2_ArgumentProblem
value|clear_enumeration
end_define

begin_define
define|#
directive|define
name|externalize_Clearinghouse2_ArgumentProblem
value|externalize_enumeration
end_define

begin_define
define|#
directive|define
name|internalize_Clearinghouse2_ArgumentProblem
value|internalize_enumeration
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_ArgumentProblem
name|problem
decl_stmt|;
name|Clearinghouse2_WhichArgument
name|which
decl_stmt|;
block|}
name|T_cn2_28
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_cn2_28
parameter_list|(
name|p
parameter_list|)
value|2
end_define

begin_define
define|#
directive|define
name|clear_T_cn2_28
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Clearinghouse2_ArgumentError
value|(ERROR_OFFSET+2)
end_define

begin_define
define|#
directive|define
name|Clearinghouse2_ArgumentErrorArgs
value|T_cn2_28
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Authentication1_Problem
name|problem
decl_stmt|;
block|}
name|T_cn2_29
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_cn2_29
parameter_list|(
name|p
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|clear_T_cn2_29
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Clearinghouse2_AuthenticationError
value|(ERROR_OFFSET+6)
end_define

begin_define
define|#
directive|define
name|Clearinghouse2_AuthenticationErrorArgs
value|T_cn2_29
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|accessRightsInsufficient
init|=
literal|1
block|,
name|tooBusy
init|=
literal|2
block|,
name|serverDown
init|=
literal|3
block|,
name|useCourier
init|=
literal|4
block|,
name|other
init|=
literal|5
block|}
name|Clearinghouse2_CallProblem
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_CallProblem
value|sizeof_enumeration
end_define

begin_define
define|#
directive|define
name|clear_Clearinghouse2_CallProblem
value|clear_enumeration
end_define

begin_define
define|#
directive|define
name|externalize_Clearinghouse2_CallProblem
value|externalize_enumeration
end_define

begin_define
define|#
directive|define
name|internalize_Clearinghouse2_CallProblem
value|internalize_enumeration
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_CallProblem
name|problem
decl_stmt|;
block|}
name|T_cn2_30
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_cn2_30
parameter_list|(
name|p
parameter_list|)
value|1
end_define

begin_define
define|#
directive|define
name|clear_T_cn2_30
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|Clearinghouse2_CallError
value|(ERROR_OFFSET+1)
end_define

begin_define
define|#
directive|define
name|Clearinghouse2_CallErrorArgs
value|T_cn2_30
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|missing
init|=
literal|20
block|,
name|wrongType
init|=
literal|21
block|}
name|Clearinghouse2_PropertyProblem
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_PropertyProblem
value|sizeof_enumeration
end_define

begin_define
define|#
directive|define
name|clear_Clearinghouse2_PropertyProblem
value|clear_enumeration
end_define

begin_define
define|#
directive|define
name|externalize_Clearinghouse2_PropertyProblem
value|externalize_enumeration
end_define

begin_define
define|#
directive|define
name|internalize_Clearinghouse2_PropertyProblem
value|internalize_enumeration
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_PropertyProblem
name|problem
decl_stmt|;
name|Clearinghouse2_ThreePartName
name|distinguishedObject
decl_stmt|;
block|}
name|T_cn2_31
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Clearinghouse2_PropertyError
value|(ERROR_OFFSET+3)
end_define

begin_define
define|#
directive|define
name|Clearinghouse2_PropertyErrorArgs
value|T_cn2_31
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|noChange
init|=
literal|30
block|,
name|outOfDate
init|=
literal|31
block|,
name|objectOverflow
init|=
literal|32
block|,
name|databaseOverflow
init|=
literal|33
block|}
name|Clearinghouse2_UpdateProblem
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Clearinghouse2_UpdateProblem
value|sizeof_enumeration
end_define

begin_define
define|#
directive|define
name|clear_Clearinghouse2_UpdateProblem
value|clear_enumeration
end_define

begin_define
define|#
directive|define
name|externalize_Clearinghouse2_UpdateProblem
value|externalize_enumeration
end_define

begin_define
define|#
directive|define
name|internalize_Clearinghouse2_UpdateProblem
value|internalize_enumeration
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_UpdateProblem
name|problem
decl_stmt|;
name|Boolean
name|found
decl_stmt|;
name|Clearinghouse2_WhichArgument
name|which
decl_stmt|;
name|Clearinghouse2_ThreePartName
name|distinguishedObject
decl_stmt|;
block|}
name|T_cn2_32
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Clearinghouse2_UpdateError
value|(ERROR_OFFSET+4)
end_define

begin_define
define|#
directive|define
name|Clearinghouse2_UpdateErrorArgs
value|T_cn2_32
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_ThreePartName
name|hint
decl_stmt|;
block|}
name|T_cn2_33
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Clearinghouse2_WrongServer
value|(ERROR_OFFSET+5)
end_define

begin_define
define|#
directive|define
name|Clearinghouse2_WrongServerArgs
value|T_cn2_33
end_define

begin_function_decl
specifier|extern
name|void
name|Clearinghouse2_CreateObject
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|Clearinghouse2_DeleteObject
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_ThreePartName
name|distinguishedObject
decl_stmt|;
block|}
name|Clearinghouse2_LookupObjectResults
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|Clearinghouse2_LookupObjectResults
name|Clearinghouse2_LookupObject
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|Clearinghouse2_ListOrganizations
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|Clearinghouse2_ListDomain
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|Clearinghouse2_ListObjects
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_ThreePartName
name|distinguishedObject
decl_stmt|;
block|}
name|Clearinghouse2_ListAliasesOfResults
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|Clearinghouse2_ListAliasesOfResults
name|Clearinghouse2_ListAliasesOf
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_ThreePartName
name|distinguishedObject
decl_stmt|;
block|}
name|Clearinghouse2_CreateAliasResults
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|Clearinghouse2_CreateAliasResults
name|Clearinghouse2_CreateAlias
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_ThreePartName
name|distinguishedObject
decl_stmt|;
block|}
name|Clearinghouse2_DeleteAliasResults
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|Clearinghouse2_DeleteAliasResults
name|Clearinghouse2_DeleteAlias
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|Clearinghouse2_ListAliases
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_ThreePartName
name|distinguishedObject
decl_stmt|;
block|}
name|Clearinghouse2_DeletePropertyResults
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|Clearinghouse2_DeletePropertyResults
name|Clearinghouse2_DeleteProperty
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_ThreePartName
name|distinguishedObject
decl_stmt|;
name|Clearinghouse2_Properties
name|properties
decl_stmt|;
block|}
name|Clearinghouse2_ListPropertiesResults
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|Clearinghouse2_ListPropertiesResults
name|Clearinghouse2_ListProperties
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_ThreePartName
name|distinguishedObject
decl_stmt|;
block|}
name|Clearinghouse2_AddItemPropertyResults
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|Clearinghouse2_AddItemPropertyResults
name|Clearinghouse2_AddItemProperty
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_ThreePartName
name|distinguishedObject
decl_stmt|;
name|Clearinghouse2_Item
name|value
decl_stmt|;
block|}
name|Clearinghouse2_RetrieveItemResults
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|Clearinghouse2_RetrieveItemResults
name|Clearinghouse2_RetrieveItem
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_ThreePartName
name|distinguishedObject
decl_stmt|;
block|}
name|Clearinghouse2_ChangeItemResults
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|Clearinghouse2_ChangeItemResults
name|Clearinghouse2_ChangeItem
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_ThreePartName
name|distinguishedObject
decl_stmt|;
block|}
name|Clearinghouse2_AddGroupPropertyResults
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|Clearinghouse2_AddGroupPropertyResults
name|Clearinghouse2_AddGroupProperty
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_ThreePartName
name|distinguishedObject
decl_stmt|;
block|}
name|Clearinghouse2_RetrieveMembersResults
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|Clearinghouse2_RetrieveMembersResults
name|Clearinghouse2_RetrieveMembers
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_ThreePartName
name|distinguishedObject
decl_stmt|;
block|}
name|Clearinghouse2_AddMemberResults
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|Clearinghouse2_AddMemberResults
name|Clearinghouse2_AddMember
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_ThreePartName
name|distinguishedObject
decl_stmt|;
block|}
name|Clearinghouse2_AddSelfResults
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|Clearinghouse2_AddSelfResults
name|Clearinghouse2_AddSelf
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_ThreePartName
name|distinguishedObject
decl_stmt|;
block|}
name|Clearinghouse2_DeleteMemberResults
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|Clearinghouse2_DeleteMemberResults
name|Clearinghouse2_DeleteMember
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_ThreePartName
name|distinguishedObject
decl_stmt|;
block|}
name|Clearinghouse2_DeleteSelfResults
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|Clearinghouse2_DeleteSelfResults
name|Clearinghouse2_DeleteSelf
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|Boolean
name|isMember
decl_stmt|;
name|Clearinghouse2_ThreePartName
name|distinguishedObject
decl_stmt|;
block|}
name|Clearinghouse2_IsMemberResults
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|Clearinghouse2_IsMemberResults
name|Clearinghouse2_IsMember
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|Clearinghouse2_NetworkAddressList
name|address
decl_stmt|;
block|}
name|Clearinghouse2_RetrieveAddressesResults
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|Clearinghouse2_RetrieveAddressesResults
name|Clearinghouse2_RetrieveAddresses
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|Clearinghouse2_ListDomainServed
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|__Clearinghouse
end_endif

end_unit

