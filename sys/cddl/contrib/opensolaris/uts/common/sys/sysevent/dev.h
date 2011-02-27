begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SYSEVENT_DEV_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SYSEVENT_DEV_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/sysevent/eventdefs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/*  * Event schema for EC_DEV_ADD/ESC_DISK  *  *	Event Class 	- EC_DEV_ADD  *	Event Sub-Class - ESC_DISK  *  *	Attribute Name	- EV_VERSION  *	Attribute Type	- DATA_TYPE_INT32  *	Attribute Value	- event version number  *  *	Attribute Name	- DEV_NAME  *	Attribute Type	- DATA_TYPE_STRING  *	Attribute Value	- /dev name to the raw device.  *			  The name does not include the slice number component.  *  *	Attribute Name	- DEV_PHYS_PATH  *	Attribute Type	- DATA_TYPE_STRING  *	Attribute Value	- physical path of the device without the "/devices"  *			  prefix.  *  *	Attribute Name	- DEV_DRIVER_NAME  *	Attribute Type	- DATA_TYPE_STRING  *	Attribute Value	- driver name  *  *	Attribute Name	- DEV_INSTANCE  *	Attribute Type	- DATA_TYPE_INT32  *	Attribute Value	- driver instance number  *  *	Attribute Name	- DEV_PROP_PREFIX<devinfo_node_property>  *	Attribute Type	- data type of the devinfo_node_property  *	Attribute Value	- value of the devinfo_node_property  *  *  * Event schema for EC_DEV_ADD/ESC_NETWORK  *  *	Event Class 	- EC_DEV_ADD  *	Event Sub-Class - ESC_NETWORK  *  *	Attribute Name	- EV_VERSION  *	Attribute Type	- DATA_TYPE_INT32  *	Attribute Value	- event version number  *  *	Attribute Name	- DEV_NAME  *	Attribute Type	- DATA_TYPE_STRING  *	Attribute Value	- /dev name associated with the device if exists.  *			  /dev name associated with the driver for DLPI  *			  Style-2 only drivers.  *  *	Attribute Name	- DEV_PHYS_PATH  *	Attribute Type	- DATA_TYPE_STRING  *	Attribute Value	- physical path of the device without the "/devices"  *			  prefix.  *  *	Attribute Name	- DEV_DRIVER_NAME  *	Attribute Type	- DATA_TYPE_STRING  *	Attribute Value	- driver name  *  *	Attribute Name	- DEV_INSTANCE  *	Attribute Type	- DATA_TYPE_INT32  *	Attribute Value	- driver instance number  *  *	Attribute Name	- DEV_PROP_PREFIX<devinfo_node_property>  *	Attribute Type	- data type of the devinfo_node_property  *	Attribute Value	- value of the devinfo_node_property  *  *  * Event schema for EC_DEV_ADD/ESC_PRINTER  *  *	Event Class 	- EC_DEV_ADD  *	Event Sub-Class - ESC_PRINTER  *  *	Attribute Name	- EV_VERSION  *	Attribute Type	- DATA_TYPE_INT32  *	Attribute Value	- event version number  *  *	Attribute Name	- DEV_NAME  *	Attribute Type	- DATA_TYPE_STRING  *	Attribute Value	- /dev/printers name associated with the device  *			  if exists.  *			  /dev name associated with the device if it exists  *  *	Attribute Name	- DEV_PHYS_PATH  *	Attribute Type	- DATA_TYPE_STRING  *	Attribute Value	- physical path of the device without the "/devices"  *			  prefix.  *  *	Attribute Name	- DEV_DRIVER_NAME  *	Attribute Type	- DATA_TYPE_STRING  *	Attribute Value	- driver name  *  *	Attribute Name	- DEV_INSTANCE  *	Attribute Type	- DATA_TYPE_INT32  *	Attribute Value	- driver instance number  *  *	Attribute Name	- DEV_PROP_PREFIX<devinfo_node_property>  *	Attribute Type	- data type of the devinfo_node_property  *	Attribute Value	- value of the devinfo_node_property  *  *  * Event schema for EC_DEV_REMOVE/ESC_DISK  *  *	Event Class 	- EC_DEV_REMOVE  *	Event Sub-Class - ESC_DISK  *  *	Attribute Name	- EV_VERSION  *	Attribute Type	- DATA_TYPE_INT32  *	Attribute Value	- event version number  *  *	Attribute Name	- DEV_NAME  *	Attribute Type	- DATA_TYPE_STRING  *	Attribute Value	- /dev name to the raw device.  *			  The name does not include the slice number component.  *  *	Attribute Name	- DEV_PHYS_PATH  *	Attribute Type	- DATA_TYPE_STRING  *	Attribute Value	- physical path of the device without the "/devices"  *			  prefix.  *  *	Attribute Name	- DEV_DRIVER_NAME  *	Attribute Type	- DATA_TYPE_STRING  *	Attribute Value	- driver name  *  *	Attribute Name	- DEV_INSTANCE  *	Attribute Type	- DATA_TYPE_INT32  *	Attribute Value	- driver instance number  *  *  * Event schema for EC_DEV_REMOVE/ESC_NETWORK  *  *	Event Class 	- EC_DEV_REMOVE  *	Event Sub-Class - ESC_NETWORK  *  *	Attribute Name	- EV_VERSION  *	Attribute Type	- DATA_TYPE_INT32  *	Attribute Value	- event version number  *  *	Attribute Name	- DEV_NAME  *	Attribute Type	- DATA_TYPE_STRING  *	Attribute Value	- /dev name associated with the device if exists.  *			  /dev name associated with the driver for DLPI  *			  Style-2 only drivers.  *  *	Attribute Name	- DEV_PHYS_PATH  *	Attribute Type	- DATA_TYPE_STRING  *	Attribute Value	- physical path of the device without the "/devices"  *			  prefix.  *  *	Attribute Name	- DEV_DRIVER_NAME  *	Attribute Type	- DATA_TYPE_STRING  *	Attribute Value	- driver name  *  *	Attribute Name	- DEV_INSTANCE  *	Attribute Type	- DATA_TYPE_INT32  *	Attribute Value	- driver instance number  *  *  * Event schema for EC_DEV_REMOVE/ESC_PRINTER  *  *	Event Class 	- EC_DEV_REMOVE  *	Event Sub-Class - ESC_PRINTER  *  *	Attribute Name	- EV_VERSION  *	Attribute Type	- DATA_TYPE_INT32  *	Attribute Value	- event version number  *  *	Attribute Name	- DEV_NAME  *	Attribute Type	- DATA_TYPE_STRING  *	Attribute Value	- /dev/printers name associated with the device  *			  if exists.  *			  /dev name associated with the device if it exists  *  *	Attribute Name	- DEV_PHYS_PATH  *	Attribute Type	- DATA_TYPE_STRING  *	Attribute Value	- physical path of the device without the "/devices"  *			  prefix.  *  *	Attribute Name	- DEV_DRIVER_NAME  *	Attribute Type	- DATA_TYPE_STRING  *	Attribute Value	- driver name  *  *	Attribute Name	- DEV_INSTANCE  *	Attribute Type	- DATA_TYPE_INT32  *	Attribute Value	- driver instance number  *  *  * Event schema for EC_DEV_BRANCH/ESC_DEV_BRANCH_ADD or ESC_DEV_BRANCH_REMOVE  *  *	Event Class 	- EC_DEV_BRANCH  *	Event Sub-Class - ESC_DEV_BRANCH_ADD or ESC_DEV_BRANCH_REMOVE  *  *	Attribute Name	- EV_VERSION  *	Attribute Type	- DATA_TYPE_INT32  *	Attribute Value	- event version number  *  *	Attribute Name	- DEV_PHYS_PATH  *	Attribute Type	- DATA_TYPE_STRING  *	Attribute Value	- physical path to the root node of the device subtree  *			  without the "/devices" prefix.  */
define|#
directive|define
name|EV_VERSION
value|"version"
define|#
directive|define
name|DEV_PHYS_PATH
value|"phys_path"
define|#
directive|define
name|DEV_NAME
value|"dev_name"
define|#
directive|define
name|DEV_DRIVER_NAME
value|"driver_name"
define|#
directive|define
name|DEV_INSTANCE
value|"instance"
define|#
directive|define
name|DEV_PROP_PREFIX
value|"prop-"
define|#
directive|define
name|EV_V1
value|1
comment|/* maximum number of devinfo node properties added to the event */
define|#
directive|define
name|MAX_PROP_COUNT
value|100
comment|/* only properties with size less than PROP_LEN_LIMIT are added to the event */
define|#
directive|define
name|PROP_LEN_LIMIT
value|1024
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_SYSEVENT_DEV_H */
end_comment

end_unit

