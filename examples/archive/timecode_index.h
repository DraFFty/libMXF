/*
 * $Id: timecode_index.h,v 1.1 2007/09/11 13:24:46 stuart_hc Exp $
 *
 * 
 *
 * Copyright (C) 2006  Philip de Nier <philipn@users.sourceforge.net>
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
 
#ifndef __TIMECODE_INDEX_H__
#define __TIMECODE_INDEX_H__

#ifdef __cplusplus
extern "C" 
{
#endif


#include <mxf/mxf_list.h>
#include <mxf/mxf_types.h>
#include <archive_types.h>


typedef struct
{
    int64_t timecodePos;
    int64_t duration;
} TimecodeIndexElement;

typedef struct
{
    TimecodeIndexElement* elements;
    int numElements;
} TimecodeIndexArray;

typedef struct
{
    int arraySize;
    MXFList indexArrays;
} TimecodeIndex;


typedef struct
{
    MXFListIterator indexArrayIter;
    TimecodeIndex* index;
    int elementNum;
    int64_t elementOffset;
    int64_t position;
    int atEnd;
    int beforeStart;
} TimecodeIndexSearcher;


void initialise_timecode_index(TimecodeIndex* index, int arraySize);
void clear_timecode_index(TimecodeIndex* index);

int add_timecode(TimecodeIndex* index, ArchiveTimecode* timecode);


void initialise_timecode_index_searcher(TimecodeIndex* index, TimecodeIndexSearcher* searcher);

int find_timecode(TimecodeIndexSearcher* searcher, int64_t position, ArchiveTimecode* timecode);
int find_position(TimecodeIndexSearcher* searcher, const ArchiveTimecode* timecode, int64_t* position);

int find_position_at_dual_timecode(TimecodeIndexSearcher* vitcSearcher, const ArchiveTimecode* vitcTimecode, 
    TimecodeIndexSearcher* ltcSearcher, const ArchiveTimecode* ltcTimecode, int64_t* position);


#ifdef __cplusplus
}
#endif


#endif

