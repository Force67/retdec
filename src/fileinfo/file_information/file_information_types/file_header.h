/**
 * @file src/fileinfo/file_information/file_information_types/file_header.h
 * @brief Class for file header.
 * @copyright (c) 2017 Avast Software, licensed under the MIT license
 */

#ifndef FILEINFO_FILE_INFORMATION_FILE_INFORMATION_TYPES_FILE_HEADER_H
#define FILEINFO_FILE_INFORMATION_FILE_INFORMATION_TYPES_FILE_HEADER_H

#include <limits>

#include "fileinfo/file_information/file_information_types/flags.h"

namespace retdec {
namespace fileinfo {

/**
 * Class for save information from file header(s).
 *
 * Value std::numeric_limits<unsigned long long>::max() mean unspecified value or error for unsigned integer types.
 */
class FileHeader
{
	private:
		std::string timeStamp;                      ///< time stamp
		std::string fileStatus;                     ///< state of file (e.g. ROM image)
		std::string fileVersion;                    ///< version of file
		std::string fileHeaderVersion;              ///< version of file header
		std::string osAbi;                          ///< target operation system or ABI
		std::string osAbiVersion;                   ///< version of operation system or ABI
		Flags fileFlags;                            ///< file flags
		Flags dllFlags;                             ///< DLL flags (set only if file is dynamic-link library)
		unsigned long long numberOfBitsInByte = std::numeric_limits<unsigned long long>::max();      ///< number of bits in one byte
		unsigned long long numberOfBitsInWord = std::numeric_limits<unsigned long long>::max();      ///< number of bits in one word
		unsigned long long fileHeaderSize = std::numeric_limits<unsigned long long>::max();          ///< size of this header
		unsigned long long segmentTableOffset = std::numeric_limits<unsigned long long>::max();      ///< offset of segment table in file
		unsigned long long segmentTableEntrySize = std::numeric_limits<unsigned long long>::max();   ///< size of one entry in segment table
		unsigned long long segmentTableSize = std::numeric_limits<unsigned long long>::max();        ///< size of segment table (size of header of segments)
		unsigned long long numberOfSegments = std::numeric_limits<unsigned long long>::max();        ///< number of segments in file
		unsigned long long sectionTableOffset = std::numeric_limits<unsigned long long>::max();      ///< offset of section table in file
		unsigned long long sectionTableEntrySize = std::numeric_limits<unsigned long long>::max();   ///< size of one entry in section table
		unsigned long long sectionTableSize = std::numeric_limits<unsigned long long>::max();        ///< size of section table (size of header of sections)
		unsigned long long declNumberOfSections = std::numeric_limits<unsigned long long>::max();    ///< declared number of sections in file
		unsigned long long coffFileHeaderSize = std::numeric_limits<unsigned long long>::max();      ///< size of COFF file header
		unsigned long long optionalHeaderSize = std::numeric_limits<unsigned long long>::max();      ///< size of optional header
		unsigned long long checksum = std::numeric_limits<unsigned long long>::max();                ///< file checksum
		unsigned long long stackReserveSize = std::numeric_limits<unsigned long long>::max();        ///< size of the stack to reserve
		unsigned long long stackCommitSize = std::numeric_limits<unsigned long long>::max();         ///< size of the stack to commit
		unsigned long long heapReserveSize = std::numeric_limits<unsigned long long>::max();         ///< size of the local heap space to reserve
		unsigned long long heapCommitSize = std::numeric_limits<unsigned long long>::max();          ///< size of the local heap space to commit
		unsigned long long numberOfDataDirectories = std::numeric_limits<unsigned long long>::max(); ///< number of data directories
		unsigned long long numberOfSymbolTables = std::numeric_limits<unsigned long long>::max();    ///< number of symbol tables
		unsigned long long overlayOffset = std::numeric_limits<unsigned long long>::max();           ///< offset of overlay
		unsigned long long overlaySize = std::numeric_limits<unsigned long long>::max();             ///< size of overlay
		double overlayEntropy = std::numeric_limits<double>::min();                      ///< overlay data entropy
	public:
		/// @name Getters
		/// @{
		std::string getTimeStamp() const;
		std::string getFileStatus() const;
		std::string getFileVersion() const;
		std::string getFileHeaderVersion() const;
		std::string getOsAbi() const;
		std::string getOsAbiVersion() const;
		unsigned long long getFileFlagsSize() const;
		unsigned long long getFileFlags() const;
		std::string getFileFlagsStr() const;
		std::size_t getNumberOfFileFlagsDescriptors() const;
		void getFileFlagsDescriptors(std::vector<std::string> &desc, std::vector<std::string> &abb) const;
		unsigned long long getDllFlagsSize() const;
		unsigned long long getDllFlags() const;
		std::string getDllFlagsStr() const;
		std::size_t getNumberOfDllFlagsDescriptors() const;
		void getDllFlagsDescriptors(std::vector<std::string> &desc, std::vector<std::string> &abb) const;
		std::string getNumberOfBitsInByteStr() const;
		std::string getNumberOfBitsInWordStr() const;
		std::string getFileHeaderSizeStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getSegmentTableOffsetStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getSegmentTableEntrySizeStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getSegmentTableSizeStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getNumberOfSegmentsStr() const;
		std::string getSectionTableOffsetStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getSectionTableEntrySizeStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getSectionTableSizeStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getDeclaredNumberOfSectionsStr() const;
		std::string getCoffFileHeaderSizeStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getOptionalHeaderSizeStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getChecksumStr() const;
		std::string getStackReserveSizeStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getStackCommitSizeStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getHeapReserveSizeStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getHeapCommitSizeStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getNumberOfDataDirectoriesStr() const;
		std::string getNumberOfSymbolTablesStr() const;
		std::string getOverlayOffsetStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getOverlaySizeStr(std::ios_base &(* format)(std::ios_base &)) const;
		std::string getOverlayEntropyStr(std::ios_base &(* format)(std::ios_base &)) const;
		/// @}

		/// @name Setters
		/// @{
		void setTimeStamp(std::string timestamp);
		void setFileStatus(std::string status);
		void setFileVersion(std::string version);
		void setFileHeaderVersion(std::string version);
		void setOsAbi(std::string osabi);
		void setOsAbiVersion(std::string abiversion);
		void setFileFlagsSize(unsigned long long size);
		void setFileFlags(unsigned long long flagsArray);
		void setDllFlagsSize(unsigned long long size);
		void setDllFlags(unsigned long long flagsArray);
		void setNumberOfBitsInByte(unsigned long long bitsInByte);
		void setNumberOfBitsInWord(unsigned long long bitsInWord);
		void setFileHeaderSize(unsigned long long headerSize);
		void setSegmentTableOffset(unsigned long long offset);
		void setSegmentTableEntrySize(unsigned long long entrySize);
		void setSegmentTableSize(unsigned long long tableSize);
		void setNumberOfSegments(unsigned long long noOfSegments);
		void setSectionTableOffset(unsigned long long offset);
		void setSectionTableEntrySize(unsigned long long entrySize);
		void setSectionTableSize(unsigned long long tableSize);
		void setDeclaredNumberOfSections(unsigned long long noOfSections);
		void setActualNumberOfSections(unsigned long long noOfSections);
		void setCoffFileHeaderSize(unsigned long long headerSize);
		void setOptionalHeaderSize(unsigned long long headerSize);
		void setChecksum(unsigned long long fileChecksum);
		void setStackReserveSize(unsigned long long size);
		void setStackCommitSize(unsigned long long size);
		void setHeapReserveSize(unsigned long long size);
		void setHeapCommitSize(unsigned long long size);
		void setNumberOfDataDirectories(unsigned long long directories);
		void setNumberOfSymbolTables(unsigned long long tables);
		void setOverlayOffset(unsigned long long offset);
		void setOverlaySize(unsigned long long size);
		void setOverlayEntropy(double entr);
		/// @}

		/// @name Other methods
		/// @{
		void addFileFlagsDescriptor(std::string descriptor, std::string abbreviation);
		void clearFileFlagsDescriptors();
		void addDllFlagsDescriptor(std::string descriptor, std::string abbreviation);
		void clearDllFlagsDescriptors();
		/// @}
};

} // namespace fileinfo
} // namespace retdec

#endif
