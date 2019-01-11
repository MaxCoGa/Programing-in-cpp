#include <iostream>
#include <string>

using namespace std;

class PlayList {
protected:
	struct SongEntry {
		string d_artist;
		string d_title;
		SongEntry* d_next;
	};
	int d_size = 0;
	SongEntry* d_list = nullptr;
public:
	PlayList() = default;
	
	PlayList( const PlayList& );
	virtual ~PlayList();
	
	PlayList& operator=( const PlayList& ); 
};


class Top5 : public PlayList {
public:
	Top5() = default;
	
	Top5( const Top5& );
	~Top5();
	
	Top5&	operator=( const Top5& );

	bool append( string artist, string title) {
		if  ( d_size >= 5 ) return false;
		SongEntry* d_tmp = d_list;
		d_list = new SongEntry{ artist, title, d_tmp };
		++d_size;
		return true;
	}
	
	bool remove() {
		if (d_size<=0) return false;
		SongEntry* d_tmp = d_list->d_next;
		delete d_list;
		d_list = d_tmp;
		--d_size;
		return true;
	}

	friend ostream& operator<<(ostream& os, const Top5& tp ) {
		Top5::SongEntry* ptr = tp.d_list;
		while ( ptr != nullptr ) {
			os << ptr->d_artist << " : " << ptr->d_title << endl;
			ptr = ptr->d_next;
		}
		return os;
	}
};


PlayList::PlayList( const PlayList& pl) : d_size{pl.d_size} {
	SongEntry* src = pl.d_list;
	SongEntry* dst = d_list;
	while ( src != nullptr ) {
		dst = new SongEntry(*src);
		src = src->d_next;
	}
}	

PlayList::~PlayList() {
	SongEntry* ptr = d_list;
	while ( ptr != nullptr ) {
		SongEntry* tmp = ptr->d_next;
		delete ptr;
		ptr = tmp;
	}
}

PlayList& PlayList::operator=( const PlayList& pl) {
	if ( this != &pl ) {
		d_size = pl.d_size;
		SongEntry* ptr = d_list;
		while ( ptr != nullptr ) {
			SongEntry* tmp = ptr->d_next;
			delete ptr;
			ptr = tmp;
		}
		d_list = nullptr;
		if ( pl.d_list != nullptr ) {
			SongEntry* src = pl.d_list;
			ptr = d_list = new SongEntry(*src);
			while ( src->d_next != nullptr ) {
				ptr->d_next = new SongEntry(*src->d_next);
				src = src->d_next;
				ptr = ptr->d_next;
			}
			ptr->d_next = nullptr;
		}
	}
	return *this;
}

Top5::Top5( const Top5& tp ) : PlayList{tp} {};

Top5::~Top5() {};
	
Top5&	Top5::operator=( const Top5& tp) {
	if ( this != &tp ) {
		PlayList::operator=( tp );
	}
	return *this;
}

	 
int main() {
	Top5 tp;
	tp.append("BROS", "Tell Me" );
	tp.append("Dylan Menzie", "Talk To Me");
	tp.append("Blue Rodeo", "I Can't Hide This Anymore");
	tp.append("Sam Roberts Band", "FIEND");
	tp.append("Rag'N'Bone Man", "Human");
	tp.append("Banners", "Into The Storm");
	cout << tp;
	cout << "---------------" << endl;
	Top5 tpCopy{tp};
	tp.remove();
	cout << tp;
	cout << "---------------" << endl;
	cout << tpCopy;
	cout << "---------------" << endl;
	tpCopy = tp;
	cout << tpCopy;
	return 0;
}
	
