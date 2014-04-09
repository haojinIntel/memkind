#ifndef check_include_h
#define check_include_h


using namespace std;

class Check {
  public:
    Check(const void *ptr, size_t size);
    Check(const Check &);
    ~Check();
    int check_node_hbw(size_t num_bandwidth, const int *bandwidth);
    int check_page_size(size_t page_size);
    int check_zero(void);
    int check_align(size_t align);
  private:
    const void *ptr;
    size_t size;
    void **address;
    unsigned long long start_addr;
    unsigned long long end_addr;
    ifstream ip;
    int smaps_fd;
    int num_address;
    void skip_lines(ifstream &, int num_lines);
    string skip_to_next_entry(ifstream &);
    void get_address_range(string &line, unsigned long long *start_addr,
                          unsigned long long *end_addr);
    size_t get_kpagesize(string line);
    int check_page_size(size_t page_size, void *vaddr);
};

#endif