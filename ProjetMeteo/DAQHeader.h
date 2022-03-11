#ifndef _DAQHEADER_H
#define _DAQHEADER_H

/*==========================================

              Map of DAQ File
        +-------------------------+
        |                         |
        |         Header          |
        |                         |
        +-------------------------+
        |      ChannelRange       |
        |       (Optional)        |
        +-------------------------+
        |   ChannelCompensation   |
        |   (Only for PCI-9524)   |
        +-------------------------+
        |                         |
        |         DAQ data        |
        |                         |
        |                         |
        +-------------------------+

============================================*/

#pragma pack(push, before_include)
#pragma pack(1)

/*size is 60 bytes*/
typedef struct _DAQFILE_HEADER
{
    char          ID[10];               //ex "ADLinkDAQ1"
    short         card_type;            //Pci7250, Pci9112...(include DG, HR, HG)
    short         num_of_channel;       //1, 2,...
    unsigned char channel_no;           //used only num_of_channel is 1
    long          num_of_scan;
    short         data_width;           //0: 8 bits, 1: 16 bits, 2: 32 bits
    short         channel_order;        //0: 0-1-2-3, 1: 3-2-1-0, 2: custom
    short         ad_range;
    double        scan_rate;
    short         num_of_channel_range;
    char          start_date[8];        //"12/31/99"
    char          start_time[8];        //"18:30:25"
    char          start_millisec[3];    //"360"
    char          reserved[6];
}
DAQFileHeader;


typedef struct _CHANNEL_RANGE
{
    unsigned char channel;
    unsigned char range;
}
DAQChannelRange;


typedef struct _Channel_Compensation_9524
{
    double residual_offset;
    double residual_scaling;
}
ChannelCompensation9524;


#pragma pack(pop, before_include)

#endif
