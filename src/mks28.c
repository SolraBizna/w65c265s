#include <stdio.h>
#include <inttypes.h>

#define SENTINEL_BYTE 0xC2
#define PAGE_SIZE 64

int main(int argc, char* argv[]) {
  uint8_t rec[PAGE_SIZE];
  uint32_t cur_addr = 0;
  size_t red;
  int recordno = 0;
  while((red = fread(rec, 1, PAGE_SIZE, stdin)) >= 1) {
    int n;
    for(n = red; n < PAGE_SIZE; ++n) {
      rec[n] = SENTINEL_BYTE;
    }
    for(n = 0; n < PAGE_SIZE; ++n) {
      if(rec[n] != SENTINEL_BYTE) break;
    }
    if(n < PAGE_SIZE) {
      do {
        /* this is a valid block */
        uint16_t running_sum = (PAGE_SIZE+4)
          + ((cur_addr>>16)&0xFF)
          + ((cur_addr>>8)&0xFF)
          + (cur_addr&0xFF);
        printf("S2%02X%06X", PAGE_SIZE+4, cur_addr);
        for(n = 0; n < PAGE_SIZE; ++n) {
          running_sum += rec[n];
          printf("%02X", rec[n]);
        }
        printf("%02X\n", running_sum&0xFF^0xFF);
        // bug in the monitor ROM, first record gets ignored
      } while(recordno++ == 0);
    }
    else {
      /* skip this block */
    }
    cur_addr += PAGE_SIZE;
  }
  printf("S804000000FB\n");
  return 0;
}
