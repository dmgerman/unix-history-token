begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header file contains inclusions for the main definitions and for  * any DEPENDS UPON modules.  It also contains #define commands to open  * the scope of the main definitons module.  *  * main inclusion:  */
end_comment

begin_include
include|#
directive|include
file|"Clearinghouse2.h"
end_include

begin_comment
comment|/* DEPENDS UPON BulkData NUMBER 0 VERSION 1 */
end_comment

begin_comment
comment|/* DEPENDS UPON Authentication NUMBER 14 VERSION 1 */
end_comment

begin_comment
comment|/*  * Widen scope to include all symbols defined in main inclusion:  */
end_comment

begin_typedef
typedef|typedef
name|Clearinghouse2_Organization
name|Organization
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Organization
value|sizeof_Clearinghouse2_Organization
end_define

begin_define
define|#
directive|define
name|clear_Organization
value|clear_Clearinghouse2_Organization
end_define

begin_define
define|#
directive|define
name|externalize_Organization
value|externalize_Clearinghouse2_Organization
end_define

begin_define
define|#
directive|define
name|internalize_Organization
value|internalize_Clearinghouse2_Organization
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_Domain
name|Domain
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Domain
value|sizeof_Clearinghouse2_Domain
end_define

begin_define
define|#
directive|define
name|clear_Domain
value|clear_Clearinghouse2_Domain
end_define

begin_define
define|#
directive|define
name|externalize_Domain
value|externalize_Clearinghouse2_Domain
end_define

begin_define
define|#
directive|define
name|internalize_Domain
value|internalize_Clearinghouse2_Domain
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_Object
name|Object
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Object
value|sizeof_Clearinghouse2_Object
end_define

begin_define
define|#
directive|define
name|clear_Object
value|clear_Clearinghouse2_Object
end_define

begin_define
define|#
directive|define
name|externalize_Object
value|externalize_Clearinghouse2_Object
end_define

begin_define
define|#
directive|define
name|internalize_Object
value|internalize_Clearinghouse2_Object
end_define

begin_define
define|#
directive|define
name|maxOrganizationsLength
value|Clearinghouse2_maxOrganizationsLength
end_define

begin_define
define|#
directive|define
name|maxDomainLength
value|Clearinghouse2_maxDomainLength
end_define

begin_define
define|#
directive|define
name|maxObjectLength
value|Clearinghouse2_maxObjectLength
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_OrganizationName
name|OrganizationName
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_OrganizationName
value|sizeof_Clearinghouse2_OrganizationName
end_define

begin_define
define|#
directive|define
name|clear_OrganizationName
value|clear_Clearinghouse2_OrganizationName
end_define

begin_define
define|#
directive|define
name|externalize_OrganizationName
value|externalize_Clearinghouse2_OrganizationName
end_define

begin_define
define|#
directive|define
name|internalize_OrganizationName
value|internalize_Clearinghouse2_OrganizationName
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_TwoPartName
name|TwoPartName
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_TwoPartName
value|sizeof_Clearinghouse2_TwoPartName
end_define

begin_define
define|#
directive|define
name|clear_TwoPartName
value|clear_Clearinghouse2_TwoPartName
end_define

begin_define
define|#
directive|define
name|externalize_TwoPartName
value|externalize_Clearinghouse2_TwoPartName
end_define

begin_define
define|#
directive|define
name|internalize_TwoPartName
value|internalize_Clearinghouse2_TwoPartName
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_DomainName
name|DomainName
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_DomainName
value|sizeof_Clearinghouse2_DomainName
end_define

begin_define
define|#
directive|define
name|clear_DomainName
value|clear_Clearinghouse2_DomainName
end_define

begin_define
define|#
directive|define
name|externalize_DomainName
value|externalize_Clearinghouse2_DomainName
end_define

begin_define
define|#
directive|define
name|internalize_DomainName
value|internalize_Clearinghouse2_DomainName
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_ThreePartName
name|ThreePartName
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_ThreePartName
value|sizeof_Clearinghouse2_ThreePartName
end_define

begin_define
define|#
directive|define
name|clear_ThreePartName
value|clear_Clearinghouse2_ThreePartName
end_define

begin_define
define|#
directive|define
name|externalize_ThreePartName
value|externalize_Clearinghouse2_ThreePartName
end_define

begin_define
define|#
directive|define
name|internalize_ThreePartName
value|internalize_Clearinghouse2_ThreePartName
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_ObjectName
name|ObjectName
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_ObjectName
value|sizeof_Clearinghouse2_ObjectName
end_define

begin_define
define|#
directive|define
name|clear_ObjectName
value|clear_Clearinghouse2_ObjectName
end_define

begin_define
define|#
directive|define
name|externalize_ObjectName
value|externalize_Clearinghouse2_ObjectName
end_define

begin_define
define|#
directive|define
name|internalize_ObjectName
value|internalize_Clearinghouse2_ObjectName
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_Name
name|Name
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Name
value|sizeof_Clearinghouse2_Name
end_define

begin_define
define|#
directive|define
name|clear_Name
value|clear_Clearinghouse2_Name
end_define

begin_define
define|#
directive|define
name|externalize_Name
value|externalize_Clearinghouse2_Name
end_define

begin_define
define|#
directive|define
name|internalize_Name
value|internalize_Clearinghouse2_Name
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_OrganizationNamePattern
name|OrganizationNamePattern
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_OrganizationNamePattern
value|sizeof_Clearinghouse2_OrganizationNamePattern
end_define

begin_define
define|#
directive|define
name|clear_OrganizationNamePattern
value|clear_Clearinghouse2_OrganizationNamePattern
end_define

begin_define
define|#
directive|define
name|externalize_OrganizationNamePattern
value|externalize_Clearinghouse2_OrganizationNamePattern
end_define

begin_define
define|#
directive|define
name|internalize_OrganizationNamePattern
value|internalize_Clearinghouse2_OrganizationNamePattern
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_DomainNamePattern
name|DomainNamePattern
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_DomainNamePattern
value|sizeof_Clearinghouse2_DomainNamePattern
end_define

begin_define
define|#
directive|define
name|clear_DomainNamePattern
value|clear_Clearinghouse2_DomainNamePattern
end_define

begin_define
define|#
directive|define
name|externalize_DomainNamePattern
value|externalize_Clearinghouse2_DomainNamePattern
end_define

begin_define
define|#
directive|define
name|internalize_DomainNamePattern
value|internalize_Clearinghouse2_DomainNamePattern
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_ObjectNamePattern
name|ObjectNamePattern
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_ObjectNamePattern
value|sizeof_Clearinghouse2_ObjectNamePattern
end_define

begin_define
define|#
directive|define
name|clear_ObjectNamePattern
value|clear_Clearinghouse2_ObjectNamePattern
end_define

begin_define
define|#
directive|define
name|externalize_ObjectNamePattern
value|externalize_Clearinghouse2_ObjectNamePattern
end_define

begin_define
define|#
directive|define
name|internalize_ObjectNamePattern
value|internalize_Clearinghouse2_ObjectNamePattern
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_T_r2_9
name|T_r2_9
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_r2_9
value|sizeof_Clearinghouse2_T_r2_9
end_define

begin_define
define|#
directive|define
name|clear_T_r2_9
value|clear_Clearinghouse2_T_r2_9
end_define

begin_define
define|#
directive|define
name|externalize_T_r2_9
value|externalize_Clearinghouse2_T_r2_9
end_define

begin_define
define|#
directive|define
name|internalize_T_r2_9
value|internalize_Clearinghouse2_T_r2_9
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_T_c2_8
name|T_c2_8
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_c2_8
value|sizeof_Clearinghouse2_T_c2_8
end_define

begin_define
define|#
directive|define
name|clear_T_c2_8
value|clear_Clearinghouse2_T_c2_8
end_define

begin_define
define|#
directive|define
name|externalize_T_c2_8
value|externalize_Clearinghouse2_T_c2_8
end_define

begin_define
define|#
directive|define
name|internalize_T_c2_8
value|internalize_Clearinghouse2_T_c2_8
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_T_c2_10
name|T_c2_10
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_c2_10
value|sizeof_Clearinghouse2_T_c2_10
end_define

begin_define
define|#
directive|define
name|clear_T_c2_10
value|clear_Clearinghouse2_T_c2_10
end_define

begin_define
define|#
directive|define
name|externalize_T_c2_10
value|externalize_Clearinghouse2_T_c2_10
end_define

begin_define
define|#
directive|define
name|internalize_T_c2_10
value|internalize_Clearinghouse2_T_c2_10
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_StreamOfDomain
name|StreamOfDomain
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_StreamOfDomain
value|sizeof_Clearinghouse2_StreamOfDomain
end_define

begin_define
define|#
directive|define
name|clear_StreamOfDomain
value|clear_Clearinghouse2_StreamOfDomain
end_define

begin_define
define|#
directive|define
name|externalize_StreamOfDomain
value|externalize_Clearinghouse2_StreamOfDomain
end_define

begin_define
define|#
directive|define
name|internalize_StreamOfDomain
value|internalize_Clearinghouse2_StreamOfDomain
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_T_r2_12
name|T_r2_12
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_r2_12
value|sizeof_Clearinghouse2_T_r2_12
end_define

begin_define
define|#
directive|define
name|clear_T_r2_12
value|clear_Clearinghouse2_T_r2_12
end_define

begin_define
define|#
directive|define
name|externalize_T_r2_12
value|externalize_Clearinghouse2_T_r2_12
end_define

begin_define
define|#
directive|define
name|internalize_T_r2_12
value|internalize_Clearinghouse2_T_r2_12
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_T_c2_11
name|T_c2_11
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_c2_11
value|sizeof_Clearinghouse2_T_c2_11
end_define

begin_define
define|#
directive|define
name|clear_T_c2_11
value|clear_Clearinghouse2_T_c2_11
end_define

begin_define
define|#
directive|define
name|externalize_T_c2_11
value|externalize_Clearinghouse2_T_c2_11
end_define

begin_define
define|#
directive|define
name|internalize_T_c2_11
value|internalize_Clearinghouse2_T_c2_11
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_T_c2_13
name|T_c2_13
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_c2_13
value|sizeof_Clearinghouse2_T_c2_13
end_define

begin_define
define|#
directive|define
name|clear_T_c2_13
value|clear_Clearinghouse2_T_c2_13
end_define

begin_define
define|#
directive|define
name|externalize_T_c2_13
value|externalize_Clearinghouse2_T_c2_13
end_define

begin_define
define|#
directive|define
name|internalize_T_c2_13
value|internalize_Clearinghouse2_T_c2_13
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_StreamOfDomainName
name|StreamOfDomainName
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_StreamOfDomainName
value|sizeof_Clearinghouse2_StreamOfDomainName
end_define

begin_define
define|#
directive|define
name|clear_StreamOfDomainName
value|clear_Clearinghouse2_StreamOfDomainName
end_define

begin_define
define|#
directive|define
name|externalize_StreamOfDomainName
value|externalize_Clearinghouse2_StreamOfDomainName
end_define

begin_define
define|#
directive|define
name|internalize_StreamOfDomainName
value|internalize_Clearinghouse2_StreamOfDomainName
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_T_r2_15
name|T_r2_15
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_r2_15
value|sizeof_Clearinghouse2_T_r2_15
end_define

begin_define
define|#
directive|define
name|clear_T_r2_15
value|clear_Clearinghouse2_T_r2_15
end_define

begin_define
define|#
directive|define
name|externalize_T_r2_15
value|externalize_Clearinghouse2_T_r2_15
end_define

begin_define
define|#
directive|define
name|internalize_T_r2_15
value|internalize_Clearinghouse2_T_r2_15
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_T_c2_14
name|T_c2_14
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_c2_14
value|sizeof_Clearinghouse2_T_c2_14
end_define

begin_define
define|#
directive|define
name|clear_T_c2_14
value|clear_Clearinghouse2_T_c2_14
end_define

begin_define
define|#
directive|define
name|externalize_T_c2_14
value|externalize_Clearinghouse2_T_c2_14
end_define

begin_define
define|#
directive|define
name|internalize_T_c2_14
value|internalize_Clearinghouse2_T_c2_14
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_T_c2_16
name|T_c2_16
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_c2_16
value|sizeof_Clearinghouse2_T_c2_16
end_define

begin_define
define|#
directive|define
name|clear_T_c2_16
value|clear_Clearinghouse2_T_c2_16
end_define

begin_define
define|#
directive|define
name|externalize_T_c2_16
value|externalize_Clearinghouse2_T_c2_16
end_define

begin_define
define|#
directive|define
name|internalize_T_c2_16
value|internalize_Clearinghouse2_T_c2_16
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_StreamOfObject
name|StreamOfObject
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_StreamOfObject
value|sizeof_Clearinghouse2_StreamOfObject
end_define

begin_define
define|#
directive|define
name|clear_StreamOfObject
value|clear_Clearinghouse2_StreamOfObject
end_define

begin_define
define|#
directive|define
name|externalize_StreamOfObject
value|externalize_Clearinghouse2_StreamOfObject
end_define

begin_define
define|#
directive|define
name|internalize_StreamOfObject
value|internalize_Clearinghouse2_StreamOfObject
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_T_r2_18
name|T_r2_18
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_r2_18
value|sizeof_Clearinghouse2_T_r2_18
end_define

begin_define
define|#
directive|define
name|clear_T_r2_18
value|clear_Clearinghouse2_T_r2_18
end_define

begin_define
define|#
directive|define
name|externalize_T_r2_18
value|externalize_Clearinghouse2_T_r2_18
end_define

begin_define
define|#
directive|define
name|internalize_T_r2_18
value|internalize_Clearinghouse2_T_r2_18
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_T_c2_17
name|T_c2_17
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_c2_17
value|sizeof_Clearinghouse2_T_c2_17
end_define

begin_define
define|#
directive|define
name|clear_T_c2_17
value|clear_Clearinghouse2_T_c2_17
end_define

begin_define
define|#
directive|define
name|externalize_T_c2_17
value|externalize_Clearinghouse2_T_c2_17
end_define

begin_define
define|#
directive|define
name|internalize_T_c2_17
value|internalize_Clearinghouse2_T_c2_17
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_T_c2_19
name|T_c2_19
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_c2_19
value|sizeof_Clearinghouse2_T_c2_19
end_define

begin_define
define|#
directive|define
name|clear_T_c2_19
value|clear_Clearinghouse2_T_c2_19
end_define

begin_define
define|#
directive|define
name|externalize_T_c2_19
value|externalize_Clearinghouse2_T_c2_19
end_define

begin_define
define|#
directive|define
name|internalize_T_c2_19
value|internalize_Clearinghouse2_T_c2_19
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_StreamOfObjectName
name|StreamOfObjectName
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_StreamOfObjectName
value|sizeof_Clearinghouse2_StreamOfObjectName
end_define

begin_define
define|#
directive|define
name|clear_StreamOfObjectName
value|clear_Clearinghouse2_StreamOfObjectName
end_define

begin_define
define|#
directive|define
name|externalize_StreamOfObjectName
value|externalize_Clearinghouse2_StreamOfObjectName
end_define

begin_define
define|#
directive|define
name|internalize_StreamOfObjectName
value|internalize_Clearinghouse2_StreamOfObjectName
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_T_r2_21
name|T_r2_21
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_r2_21
value|sizeof_Clearinghouse2_T_r2_21
end_define

begin_define
define|#
directive|define
name|clear_T_r2_21
value|clear_Clearinghouse2_T_r2_21
end_define

begin_define
define|#
directive|define
name|externalize_T_r2_21
value|externalize_Clearinghouse2_T_r2_21
end_define

begin_define
define|#
directive|define
name|internalize_T_r2_21
value|internalize_Clearinghouse2_T_r2_21
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_T_c2_20
name|T_c2_20
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_c2_20
value|sizeof_Clearinghouse2_T_c2_20
end_define

begin_define
define|#
directive|define
name|clear_T_c2_20
value|clear_Clearinghouse2_T_c2_20
end_define

begin_define
define|#
directive|define
name|externalize_T_c2_20
value|externalize_Clearinghouse2_T_c2_20
end_define

begin_define
define|#
directive|define
name|internalize_T_c2_20
value|internalize_Clearinghouse2_T_c2_20
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_T_c2_22
name|T_c2_22
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_c2_22
value|sizeof_Clearinghouse2_T_c2_22
end_define

begin_define
define|#
directive|define
name|clear_T_c2_22
value|clear_Clearinghouse2_T_c2_22
end_define

begin_define
define|#
directive|define
name|externalize_T_c2_22
value|externalize_Clearinghouse2_T_c2_22
end_define

begin_define
define|#
directive|define
name|internalize_T_c2_22
value|internalize_Clearinghouse2_T_c2_22
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_StreamOfOrganization
name|StreamOfOrganization
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_StreamOfOrganization
value|sizeof_Clearinghouse2_StreamOfOrganization
end_define

begin_define
define|#
directive|define
name|clear_StreamOfOrganization
value|clear_Clearinghouse2_StreamOfOrganization
end_define

begin_define
define|#
directive|define
name|externalize_StreamOfOrganization
value|externalize_Clearinghouse2_StreamOfOrganization
end_define

begin_define
define|#
directive|define
name|internalize_StreamOfOrganization
value|internalize_Clearinghouse2_StreamOfOrganization
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_T_r2_24
name|T_r2_24
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_r2_24
value|sizeof_Clearinghouse2_T_r2_24
end_define

begin_define
define|#
directive|define
name|clear_T_r2_24
value|clear_Clearinghouse2_T_r2_24
end_define

begin_define
define|#
directive|define
name|externalize_T_r2_24
value|externalize_Clearinghouse2_T_r2_24
end_define

begin_define
define|#
directive|define
name|internalize_T_r2_24
value|internalize_Clearinghouse2_T_r2_24
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_T_c2_23
name|T_c2_23
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_c2_23
value|sizeof_Clearinghouse2_T_c2_23
end_define

begin_define
define|#
directive|define
name|clear_T_c2_23
value|clear_Clearinghouse2_T_c2_23
end_define

begin_define
define|#
directive|define
name|externalize_T_c2_23
value|externalize_Clearinghouse2_T_c2_23
end_define

begin_define
define|#
directive|define
name|internalize_T_c2_23
value|internalize_Clearinghouse2_T_c2_23
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_T_c2_25
name|T_c2_25
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_c2_25
value|sizeof_Clearinghouse2_T_c2_25
end_define

begin_define
define|#
directive|define
name|clear_T_c2_25
value|clear_Clearinghouse2_T_c2_25
end_define

begin_define
define|#
directive|define
name|externalize_T_c2_25
value|externalize_Clearinghouse2_T_c2_25
end_define

begin_define
define|#
directive|define
name|internalize_T_c2_25
value|internalize_Clearinghouse2_T_c2_25
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_StreamOfThreePartName
name|StreamOfThreePartName
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_StreamOfThreePartName
value|sizeof_Clearinghouse2_StreamOfThreePartName
end_define

begin_define
define|#
directive|define
name|clear_StreamOfThreePartName
value|clear_Clearinghouse2_StreamOfThreePartName
end_define

begin_define
define|#
directive|define
name|externalize_StreamOfThreePartName
value|externalize_Clearinghouse2_StreamOfThreePartName
end_define

begin_define
define|#
directive|define
name|internalize_StreamOfThreePartName
value|internalize_Clearinghouse2_StreamOfThreePartName
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_Property
name|Property
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Property
value|sizeof_Clearinghouse2_Property
end_define

begin_define
define|#
directive|define
name|clear_Property
value|clear_Clearinghouse2_Property
end_define

begin_define
define|#
directive|define
name|externalize_Property
value|externalize_Clearinghouse2_Property
end_define

begin_define
define|#
directive|define
name|internalize_Property
value|internalize_Clearinghouse2_Property
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_Properties
name|Properties
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Properties
value|sizeof_Clearinghouse2_Properties
end_define

begin_define
define|#
directive|define
name|clear_Properties
value|clear_Clearinghouse2_Properties
end_define

begin_define
define|#
directive|define
name|externalize_Properties
value|externalize_Clearinghouse2_Properties
end_define

begin_define
define|#
directive|define
name|internalize_Properties
value|internalize_Clearinghouse2_Properties
end_define

begin_define
define|#
directive|define
name|all
value|Clearinghouse2_all
end_define

begin_define
define|#
directive|define
name|nullProperty
value|Clearinghouse2_nullProperty
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_Item
name|Item
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Item
value|sizeof_Clearinghouse2_Item
end_define

begin_define
define|#
directive|define
name|clear_Item
value|clear_Clearinghouse2_Item
end_define

begin_define
define|#
directive|define
name|externalize_Item
value|externalize_Clearinghouse2_Item
end_define

begin_define
define|#
directive|define
name|internalize_Item
value|internalize_Clearinghouse2_Item
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_T_r2_26
name|T_r2_26
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_r2_26
value|sizeof_Clearinghouse2_T_r2_26
end_define

begin_define
define|#
directive|define
name|clear_T_r2_26
value|clear_Clearinghouse2_T_r2_26
end_define

begin_define
define|#
directive|define
name|externalize_T_r2_26
value|externalize_Clearinghouse2_T_r2_26
end_define

begin_define
define|#
directive|define
name|internalize_T_r2_26
value|internalize_Clearinghouse2_T_r2_26
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_T_r2_27
name|T_r2_27
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_T_r2_27
value|sizeof_Clearinghouse2_T_r2_27
end_define

begin_define
define|#
directive|define
name|clear_T_r2_27
value|clear_Clearinghouse2_T_r2_27
end_define

begin_define
define|#
directive|define
name|externalize_T_r2_27
value|externalize_Clearinghouse2_T_r2_27
end_define

begin_define
define|#
directive|define
name|internalize_T_r2_27
value|internalize_Clearinghouse2_T_r2_27
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_NetworkAddress
name|NetworkAddress
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_NetworkAddress
value|sizeof_Clearinghouse2_NetworkAddress
end_define

begin_define
define|#
directive|define
name|clear_NetworkAddress
value|clear_Clearinghouse2_NetworkAddress
end_define

begin_define
define|#
directive|define
name|externalize_NetworkAddress
value|externalize_Clearinghouse2_NetworkAddress
end_define

begin_define
define|#
directive|define
name|internalize_NetworkAddress
value|internalize_Clearinghouse2_NetworkAddress
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_NetworkAddressList
name|NetworkAddressList
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_NetworkAddressList
value|sizeof_Clearinghouse2_NetworkAddressList
end_define

begin_define
define|#
directive|define
name|clear_NetworkAddressList
value|clear_Clearinghouse2_NetworkAddressList
end_define

begin_define
define|#
directive|define
name|externalize_NetworkAddressList
value|externalize_Clearinghouse2_NetworkAddressList
end_define

begin_define
define|#
directive|define
name|internalize_NetworkAddressList
value|internalize_Clearinghouse2_NetworkAddressList
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_Authenticator
name|Authenticator
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_Authenticator
value|sizeof_Clearinghouse2_Authenticator
end_define

begin_define
define|#
directive|define
name|clear_Authenticator
value|clear_Clearinghouse2_Authenticator
end_define

begin_define
define|#
directive|define
name|externalize_Authenticator
value|externalize_Clearinghouse2_Authenticator
end_define

begin_define
define|#
directive|define
name|internalize_Authenticator
value|internalize_Clearinghouse2_Authenticator
end_define

begin_define
define|#
directive|define
name|wildcard
value|Clearinghouse2_wildcard
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_WhichArgument
name|WhichArgument
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_WhichArgument
value|sizeof_Clearinghouse2_WhichArgument
end_define

begin_define
define|#
directive|define
name|clear_WhichArgument
value|clear_Clearinghouse2_WhichArgument
end_define

begin_define
define|#
directive|define
name|externalize_WhichArgument
value|externalize_Clearinghouse2_WhichArgument
end_define

begin_define
define|#
directive|define
name|internalize_WhichArgument
value|internalize_Clearinghouse2_WhichArgument
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_ArgumentProblem
name|ArgumentProblem
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_ArgumentProblem
value|sizeof_Clearinghouse2_ArgumentProblem
end_define

begin_define
define|#
directive|define
name|clear_ArgumentProblem
value|clear_Clearinghouse2_ArgumentProblem
end_define

begin_define
define|#
directive|define
name|externalize_ArgumentProblem
value|externalize_Clearinghouse2_ArgumentProblem
end_define

begin_define
define|#
directive|define
name|internalize_ArgumentProblem
value|internalize_Clearinghouse2_ArgumentProblem
end_define

begin_define
define|#
directive|define
name|ArgumentError
value|Clearinghouse2_ArgumentError
end_define

begin_define
define|#
directive|define
name|ArgumentErrorArgs
value|Clearinghouse2_ArgumentErrorArgs
end_define

begin_define
define|#
directive|define
name|AuthenticationError
value|Clearinghouse2_AuthenticationError
end_define

begin_define
define|#
directive|define
name|AuthenticationErrorArgs
value|Clearinghouse2_AuthenticationErrorArgs
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_CallProblem
name|CallProblem
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_CallProblem
value|sizeof_Clearinghouse2_CallProblem
end_define

begin_define
define|#
directive|define
name|clear_CallProblem
value|clear_Clearinghouse2_CallProblem
end_define

begin_define
define|#
directive|define
name|externalize_CallProblem
value|externalize_Clearinghouse2_CallProblem
end_define

begin_define
define|#
directive|define
name|internalize_CallProblem
value|internalize_Clearinghouse2_CallProblem
end_define

begin_define
define|#
directive|define
name|CallError
value|Clearinghouse2_CallError
end_define

begin_define
define|#
directive|define
name|CallErrorArgs
value|Clearinghouse2_CallErrorArgs
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_PropertyProblem
name|PropertyProblem
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_PropertyProblem
value|sizeof_Clearinghouse2_PropertyProblem
end_define

begin_define
define|#
directive|define
name|clear_PropertyProblem
value|clear_Clearinghouse2_PropertyProblem
end_define

begin_define
define|#
directive|define
name|externalize_PropertyProblem
value|externalize_Clearinghouse2_PropertyProblem
end_define

begin_define
define|#
directive|define
name|internalize_PropertyProblem
value|internalize_Clearinghouse2_PropertyProblem
end_define

begin_define
define|#
directive|define
name|PropertyError
value|Clearinghouse2_PropertyError
end_define

begin_define
define|#
directive|define
name|PropertyErrorArgs
value|Clearinghouse2_PropertyErrorArgs
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_UpdateProblem
name|UpdateProblem
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_UpdateProblem
value|sizeof_Clearinghouse2_UpdateProblem
end_define

begin_define
define|#
directive|define
name|clear_UpdateProblem
value|clear_Clearinghouse2_UpdateProblem
end_define

begin_define
define|#
directive|define
name|externalize_UpdateProblem
value|externalize_Clearinghouse2_UpdateProblem
end_define

begin_define
define|#
directive|define
name|internalize_UpdateProblem
value|internalize_Clearinghouse2_UpdateProblem
end_define

begin_define
define|#
directive|define
name|UpdateError
value|Clearinghouse2_UpdateError
end_define

begin_define
define|#
directive|define
name|UpdateErrorArgs
value|Clearinghouse2_UpdateErrorArgs
end_define

begin_define
define|#
directive|define
name|WrongServer
value|Clearinghouse2_WrongServer
end_define

begin_define
define|#
directive|define
name|WrongServerArgs
value|Clearinghouse2_WrongServerArgs
end_define

begin_define
define|#
directive|define
name|CreateObject
value|Clearinghouse2_CreateObject
end_define

begin_define
define|#
directive|define
name|DeleteObject
value|Clearinghouse2_DeleteObject
end_define

begin_define
define|#
directive|define
name|LookupObject
value|Clearinghouse2_LookupObject
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_LookupObjectResults
name|LookupObjectResults
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_LookupObjectResults
value|sizeof_Clearinghouse2_LookupObjectResults
end_define

begin_define
define|#
directive|define
name|clear_LookupObjectResults
value|clear_Clearinghouse2_LookupObjectResults
end_define

begin_define
define|#
directive|define
name|externalize_LookupObjectResults
value|externalize_Clearinghouse2_LookupObjectResults
end_define

begin_define
define|#
directive|define
name|internalize_LookupObjectResults
value|internalize_Clearinghouse2_LookupObjectResults
end_define

begin_define
define|#
directive|define
name|ListOrganizations
value|Clearinghouse2_ListOrganizations
end_define

begin_define
define|#
directive|define
name|ListDomain
value|Clearinghouse2_ListDomain
end_define

begin_define
define|#
directive|define
name|ListObjects
value|Clearinghouse2_ListObjects
end_define

begin_define
define|#
directive|define
name|ListAliasesOf
value|Clearinghouse2_ListAliasesOf
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_ListAliasesOfResults
name|ListAliasesOfResults
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_ListAliasesOfResults
value|sizeof_Clearinghouse2_ListAliasesOfResults
end_define

begin_define
define|#
directive|define
name|clear_ListAliasesOfResults
value|clear_Clearinghouse2_ListAliasesOfResults
end_define

begin_define
define|#
directive|define
name|externalize_ListAliasesOfResults
value|externalize_Clearinghouse2_ListAliasesOfResults
end_define

begin_define
define|#
directive|define
name|internalize_ListAliasesOfResults
value|internalize_Clearinghouse2_ListAliasesOfResults
end_define

begin_define
define|#
directive|define
name|CreateAlias
value|Clearinghouse2_CreateAlias
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_CreateAliasResults
name|CreateAliasResults
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_CreateAliasResults
value|sizeof_Clearinghouse2_CreateAliasResults
end_define

begin_define
define|#
directive|define
name|clear_CreateAliasResults
value|clear_Clearinghouse2_CreateAliasResults
end_define

begin_define
define|#
directive|define
name|externalize_CreateAliasResults
value|externalize_Clearinghouse2_CreateAliasResults
end_define

begin_define
define|#
directive|define
name|internalize_CreateAliasResults
value|internalize_Clearinghouse2_CreateAliasResults
end_define

begin_define
define|#
directive|define
name|DeleteAlias
value|Clearinghouse2_DeleteAlias
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_DeleteAliasResults
name|DeleteAliasResults
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_DeleteAliasResults
value|sizeof_Clearinghouse2_DeleteAliasResults
end_define

begin_define
define|#
directive|define
name|clear_DeleteAliasResults
value|clear_Clearinghouse2_DeleteAliasResults
end_define

begin_define
define|#
directive|define
name|externalize_DeleteAliasResults
value|externalize_Clearinghouse2_DeleteAliasResults
end_define

begin_define
define|#
directive|define
name|internalize_DeleteAliasResults
value|internalize_Clearinghouse2_DeleteAliasResults
end_define

begin_define
define|#
directive|define
name|ListAliases
value|Clearinghouse2_ListAliases
end_define

begin_define
define|#
directive|define
name|DeleteProperty
value|Clearinghouse2_DeleteProperty
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_DeletePropertyResults
name|DeletePropertyResults
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_DeletePropertyResults
value|sizeof_Clearinghouse2_DeletePropertyResults
end_define

begin_define
define|#
directive|define
name|clear_DeletePropertyResults
value|clear_Clearinghouse2_DeletePropertyResults
end_define

begin_define
define|#
directive|define
name|externalize_DeletePropertyResults
value|externalize_Clearinghouse2_DeletePropertyResults
end_define

begin_define
define|#
directive|define
name|internalize_DeletePropertyResults
value|internalize_Clearinghouse2_DeletePropertyResults
end_define

begin_define
define|#
directive|define
name|ListProperties
value|Clearinghouse2_ListProperties
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_ListPropertiesResults
name|ListPropertiesResults
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_ListPropertiesResults
value|sizeof_Clearinghouse2_ListPropertiesResults
end_define

begin_define
define|#
directive|define
name|clear_ListPropertiesResults
value|clear_Clearinghouse2_ListPropertiesResults
end_define

begin_define
define|#
directive|define
name|externalize_ListPropertiesResults
value|externalize_Clearinghouse2_ListPropertiesResults
end_define

begin_define
define|#
directive|define
name|internalize_ListPropertiesResults
value|internalize_Clearinghouse2_ListPropertiesResults
end_define

begin_define
define|#
directive|define
name|AddItemProperty
value|Clearinghouse2_AddItemProperty
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_AddItemPropertyResults
name|AddItemPropertyResults
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_AddItemPropertyResults
value|sizeof_Clearinghouse2_AddItemPropertyResults
end_define

begin_define
define|#
directive|define
name|clear_AddItemPropertyResults
value|clear_Clearinghouse2_AddItemPropertyResults
end_define

begin_define
define|#
directive|define
name|externalize_AddItemPropertyResults
value|externalize_Clearinghouse2_AddItemPropertyResults
end_define

begin_define
define|#
directive|define
name|internalize_AddItemPropertyResults
value|internalize_Clearinghouse2_AddItemPropertyResults
end_define

begin_define
define|#
directive|define
name|RetrieveItem
value|Clearinghouse2_RetrieveItem
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_RetrieveItemResults
name|RetrieveItemResults
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_RetrieveItemResults
value|sizeof_Clearinghouse2_RetrieveItemResults
end_define

begin_define
define|#
directive|define
name|clear_RetrieveItemResults
value|clear_Clearinghouse2_RetrieveItemResults
end_define

begin_define
define|#
directive|define
name|externalize_RetrieveItemResults
value|externalize_Clearinghouse2_RetrieveItemResults
end_define

begin_define
define|#
directive|define
name|internalize_RetrieveItemResults
value|internalize_Clearinghouse2_RetrieveItemResults
end_define

begin_define
define|#
directive|define
name|ChangeItem
value|Clearinghouse2_ChangeItem
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_ChangeItemResults
name|ChangeItemResults
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_ChangeItemResults
value|sizeof_Clearinghouse2_ChangeItemResults
end_define

begin_define
define|#
directive|define
name|clear_ChangeItemResults
value|clear_Clearinghouse2_ChangeItemResults
end_define

begin_define
define|#
directive|define
name|externalize_ChangeItemResults
value|externalize_Clearinghouse2_ChangeItemResults
end_define

begin_define
define|#
directive|define
name|internalize_ChangeItemResults
value|internalize_Clearinghouse2_ChangeItemResults
end_define

begin_define
define|#
directive|define
name|AddGroupProperty
value|Clearinghouse2_AddGroupProperty
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_AddGroupPropertyResults
name|AddGroupPropertyResults
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_AddGroupPropertyResults
value|sizeof_Clearinghouse2_AddGroupPropertyResults
end_define

begin_define
define|#
directive|define
name|clear_AddGroupPropertyResults
value|clear_Clearinghouse2_AddGroupPropertyResults
end_define

begin_define
define|#
directive|define
name|externalize_AddGroupPropertyResults
value|externalize_Clearinghouse2_AddGroupPropertyResults
end_define

begin_define
define|#
directive|define
name|internalize_AddGroupPropertyResults
value|internalize_Clearinghouse2_AddGroupPropertyResults
end_define

begin_define
define|#
directive|define
name|RetrieveMembers
value|Clearinghouse2_RetrieveMembers
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_RetrieveMembersResults
name|RetrieveMembersResults
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_RetrieveMembersResults
value|sizeof_Clearinghouse2_RetrieveMembersResults
end_define

begin_define
define|#
directive|define
name|clear_RetrieveMembersResults
value|clear_Clearinghouse2_RetrieveMembersResults
end_define

begin_define
define|#
directive|define
name|externalize_RetrieveMembersResults
value|externalize_Clearinghouse2_RetrieveMembersResults
end_define

begin_define
define|#
directive|define
name|internalize_RetrieveMembersResults
value|internalize_Clearinghouse2_RetrieveMembersResults
end_define

begin_define
define|#
directive|define
name|AddMember
value|Clearinghouse2_AddMember
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_AddMemberResults
name|AddMemberResults
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_AddMemberResults
value|sizeof_Clearinghouse2_AddMemberResults
end_define

begin_define
define|#
directive|define
name|clear_AddMemberResults
value|clear_Clearinghouse2_AddMemberResults
end_define

begin_define
define|#
directive|define
name|externalize_AddMemberResults
value|externalize_Clearinghouse2_AddMemberResults
end_define

begin_define
define|#
directive|define
name|internalize_AddMemberResults
value|internalize_Clearinghouse2_AddMemberResults
end_define

begin_define
define|#
directive|define
name|AddSelf
value|Clearinghouse2_AddSelf
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_AddSelfResults
name|AddSelfResults
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_AddSelfResults
value|sizeof_Clearinghouse2_AddSelfResults
end_define

begin_define
define|#
directive|define
name|clear_AddSelfResults
value|clear_Clearinghouse2_AddSelfResults
end_define

begin_define
define|#
directive|define
name|externalize_AddSelfResults
value|externalize_Clearinghouse2_AddSelfResults
end_define

begin_define
define|#
directive|define
name|internalize_AddSelfResults
value|internalize_Clearinghouse2_AddSelfResults
end_define

begin_define
define|#
directive|define
name|DeleteMember
value|Clearinghouse2_DeleteMember
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_DeleteMemberResults
name|DeleteMemberResults
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_DeleteMemberResults
value|sizeof_Clearinghouse2_DeleteMemberResults
end_define

begin_define
define|#
directive|define
name|clear_DeleteMemberResults
value|clear_Clearinghouse2_DeleteMemberResults
end_define

begin_define
define|#
directive|define
name|externalize_DeleteMemberResults
value|externalize_Clearinghouse2_DeleteMemberResults
end_define

begin_define
define|#
directive|define
name|internalize_DeleteMemberResults
value|internalize_Clearinghouse2_DeleteMemberResults
end_define

begin_define
define|#
directive|define
name|DeleteSelf
value|Clearinghouse2_DeleteSelf
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_DeleteSelfResults
name|DeleteSelfResults
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_DeleteSelfResults
value|sizeof_Clearinghouse2_DeleteSelfResults
end_define

begin_define
define|#
directive|define
name|clear_DeleteSelfResults
value|clear_Clearinghouse2_DeleteSelfResults
end_define

begin_define
define|#
directive|define
name|externalize_DeleteSelfResults
value|externalize_Clearinghouse2_DeleteSelfResults
end_define

begin_define
define|#
directive|define
name|internalize_DeleteSelfResults
value|internalize_Clearinghouse2_DeleteSelfResults
end_define

begin_define
define|#
directive|define
name|IsMember
value|Clearinghouse2_IsMember
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_IsMemberResults
name|IsMemberResults
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_IsMemberResults
value|sizeof_Clearinghouse2_IsMemberResults
end_define

begin_define
define|#
directive|define
name|clear_IsMemberResults
value|clear_Clearinghouse2_IsMemberResults
end_define

begin_define
define|#
directive|define
name|externalize_IsMemberResults
value|externalize_Clearinghouse2_IsMemberResults
end_define

begin_define
define|#
directive|define
name|internalize_IsMemberResults
value|internalize_Clearinghouse2_IsMemberResults
end_define

begin_define
define|#
directive|define
name|RetrieveAddresses
value|Clearinghouse2_RetrieveAddresses
end_define

begin_typedef
typedef|typedef
name|Clearinghouse2_RetrieveAddressesResults
name|RetrieveAddressesResults
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sizeof_RetrieveAddressesResults
value|sizeof_Clearinghouse2_RetrieveAddressesResults
end_define

begin_define
define|#
directive|define
name|clear_RetrieveAddressesResults
value|clear_Clearinghouse2_RetrieveAddressesResults
end_define

begin_define
define|#
directive|define
name|externalize_RetrieveAddressesResults
value|externalize_Clearinghouse2_RetrieveAddressesResults
end_define

begin_define
define|#
directive|define
name|internalize_RetrieveAddressesResults
value|internalize_Clearinghouse2_RetrieveAddressesResults
end_define

begin_define
define|#
directive|define
name|ListDomainServed
value|Clearinghouse2_ListDomainServed
end_define

end_unit

