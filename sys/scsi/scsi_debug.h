begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*#define SCSIDEBUG 1*/
end_comment

begin_comment
comment|/*  * Written by Julian Elischer (julian@tfs.com)  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCSI_SCSI_DEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|_SCSI_SCSI_DEBUG_H
value|1
end_define

begin_comment
comment|/*  * These are the new debug bits.  (Sat Oct  2 12:46:46 WST 1993)  * the following DEBUG bits are defined to exist in the flags word of  * the scsi_link structure.  */
end_comment

begin_define
define|#
directive|define
name|SDEV_DB1
value|0x10
end_define

begin_comment
comment|/* scsi commands, errors, data	*/
end_comment

begin_define
define|#
directive|define
name|SDEV_DB2
value|0x20
end_define

begin_comment
comment|/* routine flow tracking */
end_comment

begin_define
define|#
directive|define
name|SDEV_DB3
value|0x40
end_define

begin_comment
comment|/* internal to routine flows	*/
end_comment

begin_define
define|#
directive|define
name|SDEV_DB4
value|0x80
end_define

begin_comment
comment|/* level 4 debugging for this dev */
end_comment

begin_comment
comment|/* target and LUN we want to debug */
end_comment

begin_define
define|#
directive|define
name|DEBUGTARG
value|9
end_define

begin_comment
comment|/*9 = dissable*/
end_comment

begin_define
define|#
directive|define
name|DEBUGLUN
value|0
end_define

begin_define
define|#
directive|define
name|DEBUGLEVEL
value|(SDEV_DB1|SDEV_DB2)
end_define

begin_comment
comment|/*  * This is the usual debug macro for use with the above bits  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SCSIDEBUG
end_ifdef

begin_define
define|#
directive|define
name|SC_DEBUG
parameter_list|(
name|sc_link
parameter_list|,
name|Level
parameter_list|,
name|Printstuff
parameter_list|)
define|\
value|if((sc_link)->flags& (Level))		\ 	{					\ 		printf("%s%d(%s%d:%d:%d): ",	\ 			sc_link->device->name,	\ 			sc_link->dev_unit,	\ 			sc_link->adapter->name,	\ 			sc_link->adapter_unit,	\ 			sc_link->target,	\ 			sc_link->lun);		\  		printf Printstuff;		\ 	}
end_define

begin_define
define|#
directive|define
name|SC_DEBUGN
parameter_list|(
name|sc_link
parameter_list|,
name|Level
parameter_list|,
name|Printstuff
parameter_list|)
define|\
value|if((sc_link)->flags& (Level))		\ 	{					\  		printf Printstuff;		\ 	}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SC_DEBUG
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|)
end_define

begin_comment
comment|/* not included */
end_comment

begin_define
define|#
directive|define
name|SC_DEBUGN
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|)
end_define

begin_comment
comment|/* not included */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_SCSI_SCSI_DEBUG_H*/
end_comment

begin_comment
comment|/* END OF FILE */
end_comment

end_unit

