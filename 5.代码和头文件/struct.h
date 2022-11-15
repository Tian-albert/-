#pragma once

#define N 50


//���巢��ʱ��ṹ�壬�����ꡢ�¡���
typedef struct _date {
	int year;
	int month;
	int day;
}Date;


//�����û��ṹ�壬�����˺š�����
typedef struct _user {
	char account[N];   //��50�������С���˺�ķ��������±ꡣע���ڶ���ʱ��ʼ���ķ�ʽ�Ͷ�����ʼ����ʽ�ǲ�һ���ģ�
	char password[N];
}User;

//�����û����ݽ��
struct user_node {
	User data;
	struct user_node* next;
};


/*//�������۽ṹ�壬�����˺š�����
typedef struct _comment {
	char comment[N];
	User user;
}Comment;*/

//�������Žṹ�壬�������⡢�����ߡ�����ʱ�䡢���ġ����ۡ�����
typedef struct _news {
	char title[500];
	User user;
	Date date;
	char content[10000];
	char comment[1000];
	char category[N];      //1.֪ͨNotice��2.����Announcement��3.��ѶNewsletter
}News;

struct news_node {
	News data;
	struct news_node* next;
};




void administrator_menu();//����Ա�˵�����
void visitor_menu();//�ÿͲ˵�����
void user_menu();//�û��˵�����
void admid_function(struct user_node* uesr_list, struct news_node* news_list);//����Ա���ܽ���
void login_interface();//��¼����
void search_menu();//��������


void admin_login(struct user_node* uesr_list, struct news_node* news_list);//�жϹ���Ա��¼����
void insert_user_node(struct user_node* head, User data);//�������û����ݽ���������ͷ����
struct user_node* create_user_node(User data);//�����µ��û����ݽ��
struct user_node* create_user_list();//�����û����������ͷ
struct news_node* create_news_list();//�����������������ͷ
struct news_node* create_news_node(News data);//�����µ��������ݽ��
void insert_news_node(struct news_node* head, News data);//�������������ݽ����������ͷ����
void print_user_list(struct user_node* head);//��ӡ�û���������
void delete_user_node_by_account(struct user_node* head, char* account);//ͨ�������û��˺�ɾ�����û�����
struct user_node* search_user_by_account(struct user_node* head, char* account);//ͨ���û��˺������û�
void print_user_node(struct user_node* cur_user_node);//��ӡ��ǰ�û�����
void print_news_list(struct news_node* head);//��ӡȫ����������
void delete_news_node_by_title(struct news_node* head, char* title,struct news_node* deleted_news_list);//ͨ���������ű���ɾ����������
void print_news_node(struct news_node* cur_news_node);//��ӡ�ض�����
struct news_node* search_news_by_title(struct news_node* head, char* title);//ͨ�����ű��������ض���������

void read_user_file(char* user_file_name, struct user_node* user_list);
void save_user_file(char* user_file_name, struct user_node* user_list);
void read_news_file(char* news_file_name, struct news_node* news_list);
void save_news_file(char* news_file_name, struct news_node* news_list);
void user_login(struct user_node* user_list, struct news_node* news_list);
int check_user_account(char account[N], char password[N], struct user_node* user_list);
void user_function(struct user_node* user_list, struct news_node* news_list);

void search_function(struct news_node* news_list);
struct news_node* search_news_by_date(struct news_node* head, News temp_news);
void search_news_by_time(struct news_node* head, Date date_1, Date date_2);
void search_news_by_category(struct news_node* head, char* category);
void combined_search(struct news_node* head, Date date_1, Date date_2, char* keyword, char* category);
int Count(struct news_node* head, Date date_1, Date date_2, char* account, int* A, int* B, int* C);

struct news_node* sorting_from_ago_to_latest(struct news_node* news_list);
struct news_node* sorting_from_latest_to_ago(struct news_node* news_list);