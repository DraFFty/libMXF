/*
 * $Id: mxf_avid_metadictionary.h,v 1.1 2008/11/07 14:12:59 philipn Exp $
 *
 * Avid (AAF) Meta-dictionary
 *
 * Copyright (C) 2008  Philip de Nier <philipn@users.sourceforge.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */
 
#ifndef __MXF_AVID_METADICTIONARY_H__
#define __MXF_AVID_METADICTIONARY_H__


#ifdef __cplusplus
extern "C" 
{
#endif



int mxf_avid_is_metadictionary(MXFDataModel* dataModel, const mxfKey* setKey);
int mxf_avid_is_metadef(MXFDataModel* dataModel, const mxfKey* setKey);


int mxf_avid_create_metadictionary(MXFHeaderMetadata* headerMetadata, MXFMetadataSet** metaDictSet);


int mxf_avid_set_metadef_items(MXFMetadataSet* set, const mxfUL* id, const mxfUTF16Char* name, const mxfUTF16Char* description);

int mxf_avid_create_classdef(MXFMetadataSet* metaDictSet, const mxfUL* id, const mxfUTF16Char* name, const mxfUTF16Char* description, const mxfUL* parentId, mxfBoolean isConcrete, MXFMetadataSet** classDefSet);
int mxf_avid_create_propertydef(MXFPrimerPack* primerPack, MXFMetadataSet* classDefSet, const mxfUL* id, const mxfUTF16Char* name, const mxfUTF16Char* description, const mxfUL* typeId, mxfBoolean isOptional, mxfLocalTag localId, mxfBoolean isUniqueIdentifier, MXFMetadataSet** propertyDefSet);

int mxf_avid_create_typedef(MXFMetadataSet* metaDictSet, const mxfKey* setId, const mxfUL* id, const mxfUTF16Char* name, const mxfUTF16Char* description, MXFMetadataSet** typeDefSet);
int mxf_avid_create_typedef_char(MXFMetadataSet* metaDictSet, const mxfUL* id, const mxfUTF16Char* name, const mxfUTF16Char* description, MXFMetadataSet** typeDefSet);
int mxf_avid_create_typedef_enum(MXFMetadataSet* metaDictSet, const mxfUL* id, const mxfUTF16Char* name, const mxfUTF16Char* description, const mxfUL* typeId, MXFMetadataSet** typeDefSet);
int mxf_avid_add_typedef_enum_element(MXFMetadataSet* typeDefSet, const mxfUTF16Char* name, int64_t value);
int mxf_avid_create_typedef_extenum(MXFMetadataSet* metaDictSet, const mxfUL* id, const mxfUTF16Char* name, const mxfUTF16Char* description, MXFMetadataSet** typeDefSet);
int mxf_avid_add_typedef_extenum_element(MXFMetadataSet* typeDefSet, const mxfUTF16Char* name, const mxfUL* value);
int mxf_avid_create_typedef_fixedarray(MXFMetadataSet* metaDictSet, const mxfUL* id, const mxfUTF16Char* name, const mxfUTF16Char* description, const mxfUL* elementTypeId, uint32_t elementCount, MXFMetadataSet** typeDefSet);
int mxf_avid_create_typedef_indirect(MXFMetadataSet* metaDictSet, const mxfUL* id, const mxfUTF16Char* name, const mxfUTF16Char* description, MXFMetadataSet** typeDefSet);
int mxf_avid_create_typedef_integer(MXFMetadataSet* metaDictSet, const mxfUL* id, const mxfUTF16Char* name, const mxfUTF16Char* description, uint8_t size, mxfBoolean isSigned, MXFMetadataSet** typeDefSet);
int mxf_avid_create_typedef_opaque(MXFMetadataSet* metaDictSet, const mxfUL* id, const mxfUTF16Char* name, const mxfUTF16Char* description, MXFMetadataSet** typeDefSet);
int mxf_avid_create_typedef_record(MXFMetadataSet* metaDictSet, const mxfUL* id, const mxfUTF16Char* name, const mxfUTF16Char* description, MXFMetadataSet** typeDefSet);
int mxf_avid_add_typedef_record_member(MXFMetadataSet* typeDefSet, const mxfUTF16Char* name, const mxfUL* typeId);
int mxf_avid_create_typedef_rename(MXFMetadataSet* metaDictSet, const mxfUL* id, const mxfUTF16Char* name, const mxfUTF16Char* description, const mxfUL* renamedTypeId, MXFMetadataSet** typeDefSet);
int mxf_avid_create_typedef_set(MXFMetadataSet* metaDictSet, const mxfUL* id, const mxfUTF16Char* name, const mxfUTF16Char* description, const mxfUL* elementTypeId, MXFMetadataSet** typeDefSet);
int mxf_avid_create_typedef_stream(MXFMetadataSet* metaDictSet, const mxfUL* id, const mxfUTF16Char* name, const mxfUTF16Char* description, MXFMetadataSet** typeDefSet);
int mxf_avid_create_typedef_string(MXFMetadataSet* metaDictSet, const mxfUL* id, const mxfUTF16Char* name, const mxfUTF16Char* description, const mxfUL* elementTypeId, MXFMetadataSet** typeDefSet);
int mxf_avid_create_typedef_strongref(MXFMetadataSet* metaDictSet, const mxfUL* id, const mxfUTF16Char* name, const mxfUTF16Char* description, const mxfUL* referencedTypeId, MXFMetadataSet** typeDefSet);
int mxf_avid_create_typedef_vararray(MXFMetadataSet* metaDictSet, const mxfUL* id, const mxfUTF16Char* name, const mxfUTF16Char* description, const mxfUL* elementTypeId, MXFMetadataSet** typeDefSet);
int mxf_avid_create_typedef_weakref(MXFMetadataSet* metaDictSet, const mxfUL* id, const mxfUTF16Char* name, const mxfUTF16Char* description, const mxfUL* referencedTypeId, MXFMetadataSet** typeDefSet);
int mxf_avid_add_typedef_weakref_target(MXFMetadataSet* typeDefSet, const mxfUL* targetId);


int mxf_initialise_metadict_read_filter(MXFReadFilter* filter);
void mxf_clear_metadict_read_filter(MXFReadFilter* filter);


int mxf_avid_create_default_metadictionary(MXFHeaderMetadata* headerMetadata, MXFMetadataSet** metaDictSet);



#ifdef __cplusplus
}
#endif


#endif


